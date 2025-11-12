#include <iostream>
using namespace std;

int n,len,LEN;
long long ans=0;
int a[5050]={-1},A[5050]={-1};

bool isPolygon(int tungs[],int len_tungs){
	int num=0,maxn=-1;
	for(int i=1;i<=len_tungs;i++){
		num+=tungs[i];
		if(tungs[i]>maxn){
			maxn=tungs[i];
		}
	}
	
	if(num>maxn*2){
		return true;
	}else{
		return false;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		len=i;
	}
	
	while(n>=3){
		for(int i=1;i<=n;i++){
			A[i]=a[i];
			LEN=i;
		}n--;
		if(isPolygon(A,LEN)){
			ans++;
		}
	}
	
	ans%=998244353;
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
