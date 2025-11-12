#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,a[100001],b[100001],c[100001],s=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			b[j]=b[j]-a[j];
			c[j]=c[j]-a[j];
			s=s+a[j];
		}
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		int j=n,k=n;
		while(j>(n/2)&&k>(n/2)){
			if(b[j]>c[k]){
				s=s+b[j];
				j--;
			}else{
				s=s+c[k];
				k--;
			}
			if(j+k<=n+(n/2)&&b[j]<0&&c[j]<0){
				break;
			}
		}
		while(j>(n/2)&&b[j]>0){
			s=s+b[j];
			j--;
		}
		while(k>(n/2)&&c[k]>0){
			s=s+c[k];
			k--;
		}
		cout<<s<<endl;
	}
	return 0;
}
