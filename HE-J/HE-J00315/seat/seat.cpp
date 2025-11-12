#include<bits/stdc++.h>
using namespace std;

int n,m,a[1005],s,nm,ans=1,r=0,c=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	nm=n*m;
	for(int i=0;i<nm;i++){
		cin>>a[i];
	}
	s=a[1];
	for(int i=0;i<nm-1;i++){
		for(int j=0;j<nm-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<nm;i++){
		ans++;
		if(a[i]==s){
			break;
		}
	}
	for(int i=0;i<ans;i++){
		if(c%2!=0){
			r+=1;
			if(r>n){
				r=n;
				c+=1;
			}
		}else if(c%2==0){
			r-=1;
			if(r<1){
				r=1;
				c+=1;
			}
		}
	}
	cout<<c<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++
