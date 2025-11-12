#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;

int n,q;
string s1[N],s2[N],que1,que2;
map <string,int> a,b;

int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<=n;i++){
		cin >>s1[i]>>s2[i];
	}
	int co=0;
	for (int i=0;i<s1[1].size();i++){
		if (s1[1][i]!='a'&&s1[1][i]!='b'||s2[1][i]!='a'&&s2[1][i]!='b'){
			co=1;
			break;
		}
	}
	if (co){
		while (q--){
			int ans=0;
			for (int i=1;i<=n;i++){
				a[s1[i]]=1;
				b[s2[i]]=1;
			}
			cin >>que1>>que2;
			int diff=0;
			for (int i=0;i<=que1.size()-1;i++)
				if (que1[i]!=que2[i])
					diff++;
			for (int i=0;i<que1.size();i++){
				for (int j=0;j+i<que1.size();j++){
					string tmp1,tmp2;
					for (int k=j;k<=j+i;k++){
						tmp1+=que1[k];
						tmp2+=que2[k];
					}
					if (a[tmp1]==1&&b[tmp2]==1&&tmp1.size()>=diff){
//						cout <<tmp1<<" "<<tmp2<<endl;
						ans++;
					}
				}
			}
			cout <<ans<<endl;
		}
	}
	else{
		while (q--){
			cin >>que1>>que2;
			int id=0;
			while (que1[id]!='b')
				id++;
			int id2=0;
			while (que2[id2]!='b')
				id2++;
			int l1=que1.size(),l2=que2.size();
			int be1=id,be2=id2,af1=l1-id-1,af2=l2-id2-1;
	//			cout <<"check:: "<<be1<<" "<<af1<<" "<<be2<<" "<<af2<<endl;
			int cha=id2-id;
			int ans=0;
			for (int i=1;i<=n;i++){
				int tmp=0;
				while (s1[i][tmp]!='b')
					tmp++;
				int cnt=0;
				while (s2[i][cnt]!='b')
					cnt++;
				if (cnt-tmp!=cha)
					continue;
				if (tmp<=be1&&s1[i].size()-tmp-1<=af1&&cnt<=be2&&s2[i].size()-cnt-1<=af2)
					ans++;
			}
			cout <<ans<<endl;
		}
	}
	return 0;
}
/*
3 1
aaba aaab
aaaba aaaab
aba aab
aaaba aaaab

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/