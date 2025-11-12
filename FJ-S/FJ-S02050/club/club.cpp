#include <bits/stdc++.h>
using namespace std;
int const N=1e5+100;
struct niko{
	int a,b,c;
	int ia,ib,ic;
};
bool f1(niko a,niko b){
	return a.a<b.a;
}
bool f2(niko a,niko b){
	return a.b<b.b;
}
bool f33(niko a,niko b){
	return a.c<b.c;
}
niko a[N];
int t[5];
int T,n,ans=0;
bool fc(char m){
	if(m=='a'&&t[1]>=n/2) return 0;
	if(m=='b'&&t[2]>=n/2) return 0;
	if(m=='c'&&t[3]>=n/2) return 0;
	return 1;
}
int f(int tt,string s){
//	cout<<s<<endl;
	for(int i=0;i<=2;i++){
		if(fc(s[i])){
			if(s[i]=='a'){
				t[1]++;
				return a[tt].a;
			}
			if(s[i]=='b'){
				t[2]++;
				return a[tt].b;
			}
			if(s[i]=='c'){
				t[3]++;
				return a[tt].c;
			}
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[1].b==a[1].c&&a[2].b==a[2].c){
			int sum=0;
			sort(a+1,a+1+n,f1);
			for(int i=n;i>=1;i--){
				if(t[1]<n/2){
					sum+=a[i].a;
					t[1]++;
				}
				else break;
			}
			cout<<sum<<endl;
			continue;
		}
		else if(a[1].c==a[2].c){
			sort(a+1,a+1+n,f2);
			for(int i=n;i>=1;i--){
				if(a[i].b>=a[i].a&&t[2]<n/2)t[2]++,ans+=a[i].b,a[i].a=0;
			}
			sort(a+1,a+1+n,f1);
			for(int i=n;i>=1;i--){
				if(t[1]<n/2)t[1]++,ans+=a[i].a;
				else break;
			}
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,f1);
		for(int i=1;i<=n;i++) a[i].ia=i;
		sort(a+1,a+1+n,f2);
		for(int i=1;i<=n;i++) a[i].ib=i;
		sort(a+1,a+1+n,f33);
		for(int i=1;i<=n;i++) a[i].ic=i;
		for(int i=1;i<=n;i++){
			int ta=a[i].ia,tb=a[i].ib,tc=a[i].ic;
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<endl;
//			cout<<ta<<' '<<tb<<' '<<tc<<endl;
			if(ta>=tb){//ab
				if(ta>=tc){
					if(tb>=tc) ans+=f(i,"abc");//abc
					else ans+=f(i,"acb");//acb
				}
				else ans+=f(i,"cab");//cab
			}
			else{//b>a
				if(tb>=tc){
					if(tc>=ta) ans+=f(i,"bca");//bca
					else ans+=f(i,"bac");//bac
				}
				else ans+=f(i,"cba");//cba
			
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/