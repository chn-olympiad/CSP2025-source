#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long x;
long long cnt;
long long sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if((x==m) || (((x^sum)==m) && (sum!=0))){
			cnt++;
			sum=0;
			
		}else{
			if(sum==0){
				sum=x;
			}else{
				sum=sum^x;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
