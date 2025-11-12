#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//ÁÐ ÐÐ 
	cin>>n>>m;
	int a[n*m+1];
	cin>>a[0];
	int li=a[0],lile=0;
	for(int i=1;i<n*m;i++){
			cin>>a[i];
	}
	for(int i=0;i<n*m-1;i++){
		for(int j=i+1;j<m*n;j++){
			if(a[i]<a[j]){
				int lil=a[i];
				a[i]=a[j];
				a[j]=lil;
			}
		}
	}
    for(int i=0;i<n*m;i++){
    	if(a[i]==li){
    		lile=i+1;
    		break;
		}
	}
	int lie=(lile-1)/m+1,hang=(lile-1)%m+1;
	if(lie%2==0){
		cout<<lie<<" "<<m-hang+1;
	}else{
		cout<<lie<<" "<<hang;
	}
	return 0;
}
