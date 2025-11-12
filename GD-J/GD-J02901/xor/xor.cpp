#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
int n,k,al;
string a[N];
PII ans[N];
string er(int u){
	string s="";
	while(u){
		s+=(u%2)+'0';
		u/=2;
	}
	return s;
}
int x(int u,int v){
	string str="";
	for(int i=u;i<=v;i++){
		string s=a[i];
		int len=s.length(),strl=str.length();
		int minl=min(len,strl),maxl=max(len,strl);
		for(int i=0;i<minl;i++){
			if(s[i]==str[i]) str[i]='0';
			else str[i]='1';
		}
		if(len==maxl){
			for(int i=minl;i<maxl;i++){
				str+=s[i];
			}
		}
	}
	int strl=str.length(),q=1,sum=0;
	for(int i=0;i<strl;i++){
		sum+=(str[i]-'0')*q;
		q*=2;
	}
	return sum;
}
bool check(int l,int r){
	bool flag=1;
	for(int i=0;i<al;i++){
		int st=ans[i].first,end=ans[i].second;
		if(l>=st&&l<=end||r<=end&&r>=st){
			flag=0;
			break;
		}
	}
	if(flag){
		ans[al++]={l,r};
		return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int num;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		a[i]=er(num);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=x(i,j);
			if(t==k){
				if(check(i,j)) res++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
} 
