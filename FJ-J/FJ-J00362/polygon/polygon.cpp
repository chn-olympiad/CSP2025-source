#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	int n,a[100],m=0;
	cin>>n;
	 for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<i;j++){
				if(a[i]<a[j]){
					swap(a[i],a[j]);
				}
		}}
		for(int i=n;i>=3;n--){
			for(int j=0;j<n;j++){
				int s=0;
				int b[100];
			for(int t=1;t=i;t++){
				b[s]=a[t];
				s++;
			}
			int maxe=0,all=0;
			for(int t=0;t<s;t++){
				all+=b[t];
				maxe=max(maxe,b[t]);
			}
			if(maxe*2>all){
				m++;
			}
		}
		}
		cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
