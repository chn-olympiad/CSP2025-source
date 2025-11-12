#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	int n,a[1000]={};
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int maxs=0,cnt=0,ans=0;
	for(int i=0;i<n;i++){
		int c=0;
		maxs=a[i];
		maxs*=2;
		for(int j=1;j<n;j++){
			if(a[j]==maxs){
				continue;
			} 
			cnt+=a[j];
			if(cnt>maxs){
				cnt-=a[j-c];
				c++;
				ans++;
				j-=c;
				continue;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
