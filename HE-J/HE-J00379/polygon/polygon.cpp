#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool pd()
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<n;i++){
		int c=0,max=0;
		for(int k=0;k<n-i;k++){
			for(int j=0+k;j<i+k;j++){
				c+=a[j];
				if(max<a[j]){
					max=a[j];
				}	
			}
			if(c>max*2){
				ans++;
			}
		}
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
