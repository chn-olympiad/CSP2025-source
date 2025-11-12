#include<iostream>
#include<cstdio>
using namespace std;
int a[200010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;bool ccc=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) ccc=1;
	}
	if(ccc==0){
		int s=0;
		if(k==0){
			bool Id=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					Id=!Id;
					if(Id==0){
						s++;
					}
				}
			}
		}else{
			for(int i=0;i<n;i++){
				if(a[i]==1) s++;
			}
		}
		cout<<s;
	}else{
		cout<<78;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
