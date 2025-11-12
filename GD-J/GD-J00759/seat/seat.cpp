#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1005];
ll s[1005][1005];
int j=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	ll R;
	int di=1;
	cin>>n>>m;
	int n1=n*m-1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a,a+n*m);
	int i=0;
	while(1==1){
		if(a[n1]==R){
			cout<<j+1<<" "<<i+1;
			break;
		}
		if(j%2==0 and i==n-1){
			j++;
			di=-1;
			if(a[n1-1]==R){
				cout<<j+1<<" "<<i+1;
				break;
			}
			n1--; 
		}
		else if(j%2!=0 and i==0){
			j++;
			di=1;
			if(a[n1-1]==R){
				cout<<j+1<<" "<<i+1;
				break;
			}
			n1--;
		}
		i+=di;
		n1--;
		
	}
	return 0;
}//fuck you,CCF
