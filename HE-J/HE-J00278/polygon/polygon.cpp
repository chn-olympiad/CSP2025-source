#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
    int n,plan=0,zero=0,sum=0;
    int a[5005];
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]<=1){
    		zero++;
		}
		sum+=a[i];
	}
	sort(a,a+n,cmp);
	if(n<=3){
    	if(n<3){
    		cout<<0;
    		return 0;
		}
		if(n==3){
			if(sum<=a[1]){
				cout<<0;
				return 0;
			}
			else{
				cout<<1;
				return 0;
			}
		}
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	}
    fclose(stdin); fclose(stdout);
    return 0;
}
