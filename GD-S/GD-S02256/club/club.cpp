#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
ll a[2][100001];
ll j[4];
ll k[4];
ll f[100001];
ll m=0;

int rob(ll o){
	int i,v;
	ll a1=0,a2=10000001,a3=0,a4=0,a5=0,a6=0,a7=0;
	
	for(i=1;i<=3;i++){
		if(a1<=j[i]){
			a6=i;
			a1=j[i];
			a3=a[1][o];
			a[1][o]=i;
			f[o]=a1;		
		}
		if(a2>=j[i]){
			a2=j[i];
			a7=i;
		}
			
	}

	if(1!=a6 && 1!=a7){
		a5=j[1];
	}
	if(2!=a6 && 2!=a7){
		a5=j[2];
	}
	if(3!=a6 && 3!=a7){
		a5=j[3];
	}	

	a[0][o]=a1-a5;
	
	k[a[1][o]]++;

	
	if(k[a[1][o]]>n/2){
		a1=1000001;
		for(i=1;i<=o;i++){
			if(a[1][i]==a[1][o] && a[0][i]<a[0][o]){
				if(a1>a[0][i]){
					a1=a[0][i];
					a4=i;
				}
			}
		}
		if(a1<a[0][o]){
			m=m-a[0][a4]+a[0][o];
			a[1][a4]=0;
		}else{
			m=m+f[o]-a[0][o];
			a[1][o]=0;
		}
		
	}else{
		m=m+f[o];
	}

	
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	ll i,o;
	for(i=1;i<=t;i++){
		cin>>n;
		m=0;
		k[1]=0;
		k[2]=0;
		k[3]=0;
		for(o=1;o<=n;o++){
			cin>>j[1]>>j[2]>>j[3];
			rob(o);

            
		}
		
		cout<<m<<endl;
	}
	
	
	return 0;
} 
