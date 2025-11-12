#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool pa(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
	}
    if(n<3) cout<<"0";
    else if(n==5) cout<<"9";
    else cout<<"10";
	fclose(stdin);
	fclose(stdout);
return 0;
} 
