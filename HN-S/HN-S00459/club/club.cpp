#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009],c[100009],n,t,w1,w2;
int at,bt,ct;
int s(int nn){
	int t=0;
	if(at*2>n||bt*2>n||ct*2>n||nn<0){
		return 0;
	}
	at++;
	cout<<t<<' ';
	t=a[nn]+s(nn-1);
	at--;
	bt++;
	cout<<t<<' ';
	t=max(t,b[nn]+s(nn-1));
	bt--;
	ct++;
	cout<<t<<' ';
	t=max(t,c[nn]+s(nn-1));
	ct--;
	cout<<t<<' ';
	return t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
				cin>>a[i]>>b[i]>>c[i];
				w1+=b[i];
				w2+=c[i];
			
		}
		if(w1){
			sort(a,a+n);
			int ans=0;
			for(int i=0;i<n/2;i++){
				ans+=a[i];
			}
		    cout<<ans<<endl;
		}
		else if(w2){
			int ans=0;
			for(int i=0;i<n;i++)
			c[i]=a[i]-b[i];
			sort(c,c+n);
			for(int i=0;i<n/2;i++){
				if(c[i]<0){
					break;
				}
				ans+=c[i];
			}
			for(int i=n/2;i<n;i++){
				if(c[i]<0) ans+=c[i];
				cout<<ans<<endl;
			}
		}
		else{
		cout<<s(n-1)<<endl;
	}
}
	return 0;
}
