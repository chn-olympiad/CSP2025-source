#include<bits/stdc++.h>
using namespace std;
int n,T;
const int N=2e5+10,M=1e7+10;
int tl[N],t1[N],t2[N],tc[N];
int c[M];
vector<int>id[M];
const int bs=5e6;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&T);
	int l=0;
	for(int j=1;j<=n;j++){
		string a,b;
		cin>>a;
		cin>>b;
		l=a.size();
		tl[j]=l;
		for(int i=0;i<l;i++){
			if((a[i]!='a'&&a[i]!='b')||(b[i]!='a'&&b[i]!='b'))break;
			if(a[i]=='b')t1[j]=i+1;
			if(b[i]=='b')t2[j]=i+1;
			if(t1[j]>0&&t2[j]>0){
				tc[j]=t1[j]-t2[j];
				c[tc[j]+bs]++;
				break;
			}
		}
		id[tc[j]+bs].push_back(j);
	}
	l=0;
	int ll=0,x=0,xx=0,ans=0,xb=0;
	bool f=false;
	while(T--){
		string a,b;
		cin>>a;
		cin>>b;
		if(f){
			puts("0");
			continue;
		}
		l=a.size();
		ll=b.size();
		if(l!=ll)continue;
		for(int i=0;i<l;i++){
			if((a[i]!='a'&&a[i]!='b')||(b[i]!='a'&&b[i]!='b')){
				f=true;
				break;
			}
			if(a[i]=='b')x=i+1;
			if(b[i]=='b')xx=i+1;
			if(x>0&&xx>0)break;
		}
		if(f){
			puts("0");
			continue;
		}
		if(c[x-xx+bs]>0){
			ans=0;
			for(int j=0;j<=c[x-xx+bs];j++){
				xb=id[x-xx+bs][j];
				if(tl[xb]<=l&&tl[xb]-max(t1[xb],t2[xb])<=l-max(x,xx)&&min(t1[xb],t2[xb])<=min(x,xx)){
					ans++;
				}
			}
			printf("%d\n",ans);
		}else puts("0");
	}
	return 0;
}
