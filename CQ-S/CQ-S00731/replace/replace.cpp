#include<iostream>
#include<string>
const int Mt=200500,Ml=2500600;
using std::string;
using std::cin;
using std::cout;
int next[10010][10010];
int n,q;
string strs[Mt][2];
void gtnx(string str,int p){
	int len=str.length();
	int i=1,j=0;
	while(i<=len){
		if(str[i-1]==str[j-1]||j==0)next[p][i++]=j++;
		else j=next[p][j];
	}
}
int kmp(string T,string S,int p){
	int lenT=T.length(),lenS=S.length();
	int i=1,j=1,f=-1;
	while(j<=lenS&&i<=lenT){
		if(T[i-1]==S[j-1]||j==0)i++,j++;
		else j=next[p][j];
		if(j==lenS){
			if(f>-1)return -1;
			f=i;j=next[p][j-1];i--;
		}
	}
	return f;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),std::cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>strs[i][0]>>strs[i][1];
	if(n<10005){
		for(int i=1;i<=n;i++)gtnx(strs[i][0],i<<1),gtnx(strs[i][1],i<<1|1);
		for(int i=1;i<=q;i++){
			string qr,qs;
			cin>>qr>>qs;
			int t=0;
			for(int i=1;i<=n;i++){
				int ll=kmp(qr,strs[i][0],i<<1);
				int rr=kmp(qs,strs[i][1],i<<1|1);
				t+=((ll+1)&&ll==rr);
			}
			cout<<t<<'\n';
		}
	}
	else{
		for(int i=1;i<=q;i++){
			string q1,q2;
			cin>>q1>>q2;
			cout<<0<<'\n';
		}
	}
	return 0;
}
