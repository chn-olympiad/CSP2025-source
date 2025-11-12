#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],ar,br,cr,l,sum,v;
int sjh(int k){
	if(k>n){
		if(sum>l){
			l=sum;
		}
	}
	else{
		for(int i=1;i<=3;i++){
			if(i==1&&ar<v){
				sum+=a[k];
				ar++;
				sjh(k+1);
				ar--;
				sum-=a[k];
			}
			else if(i==2&&br<v){
				sum+=b[k];
				br++;
				sjh(k+1);
				br--;
				sum-=b[k];
			}
			else if(i==3&&cr<v){
				sum+=c[k];
				cr++;
				sjh(k+1);
				cr--;
				sum-=c[k];
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ar=0,cr=0,br=0,l=INT_MIN,sum=0;
		v=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sjh(1);
		cout<<l<<endl;
	}
	
	return 0;
} 
