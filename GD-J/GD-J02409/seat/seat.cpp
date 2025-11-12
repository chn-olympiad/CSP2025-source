#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,m,hang,lie,flag,zuo[maxn][maxn];
struct kaoshi{
	int cheng,bian;
}arr[maxn];
bool cmp(kaoshi diyi,kaoshi dier){
	return diyi.cheng>dier.cheng;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>arr[i].cheng;
		arr[i].bian=i;
	}
	sort(arr+1,arr+len+1,cmp);
	
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			int zuow=i+n*(j-1);
			if(arr[zuow].bian==1){
				cout<<j<<" "<<i;
				flag=1;
				break;
			}
		}
		if(flag)break;
		j++;
		for(int i=n;i>=1;i--){
			int zuow=n-i+1+(j-1)*n;
			if(arr[zuow].bian==1){
				cout<<j<<" "<<i;
				break;
			}
		}
		if(flag)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
