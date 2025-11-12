#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;

int n,qq;
string s1[N],s2[N];
string a,b;
int cnt;
//int hh=0,tt=-1;
//string q[N];
//bool st[N][210];
//bool check(string s){
//	for(int i=0;i<=tt;i++)if(s==q[i])return 1;
//	return 0;
//}
//int bfs(){
//	hh=0,tt=-1,cnt=0;
//	q[++tt]=a;
//	while(hh<=tt){
//		int tk=hh;
//		string s=q[hh++];
//		if(s==b){
//			cnt++;
//			continue;
//		}
//		for(int k=1;k<=n;k++){
//			if(st[tk][k])continue;
//			int m=s1[k].size();
//			for(int i=0;i+m-1<s.size();i++){
//				string t=s.substr(i,m);
//				if(t==s1[k]){
//					string tmp;
//					if(i>=1)tmp=s.substr(0,i)+s2[k]+s.substr(i+m,s.size()-i-m);
//					else tmp=s2[k]+s.substr(i+m-1,s.size()-i-m);
//					if(tmp==b||!check(tmp)){
//						q[++tt]=tmp;
//						for(int i=1;i<=k;i++)st[tt][k]=st[tk][k];
//						st[tt][k]=1;
//					}
//				}
//			}
//		}
//	}
//	return cnt;
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>qq;
	if(n<=200){
		for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
		while(qq--){
			cin>>a>>b;
			//	
			cnt=0;
			for(int k=1;k<=n;k++){
					int m=s1[k].size();
					for(int i=0;i+m-1<a.size();i++){
						string t=a.substr(i,m);
						if(t==s1[k]){
							string tmp;
							if(i>=1)tmp=a.substr(0,i)+s2[k]+a.substr(i+m,a.size()-i-m);
							else tmp=s2[k]+a.substr(i+m-1,a.size()-i-m);
							if(tmp==b)cnt++;
						}
					}
			}
			//
			//cout<<bfs()<<endl;
			cout<<cnt<<endl;
		}
	}
	else {
		for(int i=1;i<=qq;i++)
			cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

