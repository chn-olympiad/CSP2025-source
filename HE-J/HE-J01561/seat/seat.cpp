#include<bits/stdc++.h>
using namespace std;

long long a[110];
long long n,m,k1,k2;
bool boo=true;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k1;
	for(long long i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>k1){
			k2++;
		}
	}
	for(long long s=0,i=1,j=1;s<=k2;s++){
		if(s==k2){
			cout<<j<<" "<<i;
		}if(i==n&&boo==true){
			boo=false;
			j++;
			continue;
		}else if(i==1&&boo==false){
			boo=true;
			j++;
			continue;
		}if(boo==true){
			i++;
		}else if(boo==false){
			i--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
