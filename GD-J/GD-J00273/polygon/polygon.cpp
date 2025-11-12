#include <iostream>
using namespace std;
long long a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin >> n;
	long long sum;
	for (int i=1;i<=n;i++) cin >> a[i];
	long long ans=0;
	for (int i=1;i<=n-2;i++){
		int x=max(a[i],max(a[i+1],a[i+2]));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-3;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],a[i+2])));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-4;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],a[i+2]))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-5;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],a[i+2])))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-6;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],max(a[i+6],a[i+2]))))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		sum+=a[i+6];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-7;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],max(a[i+6],max(a[i+7],a[i+2])))))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		sum+=a[i+6];
		sum+=a[i+7];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-8;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],max(a[i+6],max(a[i+7],max(a[i+8],a[i+2]))))))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		sum+=a[i+6];
		sum+=a[i+7];
		sum+=a[i+8];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-9;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],max(a[i+6],max(a[i+7],max(a[i+8],max(a[i+9],a[i+2])))))))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		sum+=a[i+6];
		sum+=a[i+7];
		sum+=a[i+8];
		sum+=a[i+9];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-10;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],max(a[i+6],max(a[i+7],max(a[i+8],max(a[i+9],max(a[i+10],a[i+2]))))))))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		sum+=a[i+6];
		sum+=a[i+7];
		sum+=a[i+8];
		sum+=a[i+9];
		sum+=a[i+10];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	for (int i=1;i<=n-11;i++){
		int x=max(a[i],max(a[i+1],max(a[i+3],max(a[i+4],max(a[i+5],max(a[i+6],max(a[i+7],max(a[i+8],max(a[i+9],max(a[i+10],max(a[i+11],a[i+2])))))))))));
		sum+=a[i];
		sum+=a[i+1];
		sum+=a[i+2];
		sum+=a[i+3];
		sum+=a[i+4];
		sum+=a[i+5];
		sum+=a[i+6];
		sum+=a[i+7];
		sum+=a[i+8];
		sum+=a[i+9];
		sum+=a[i+10];
		sum+=a[i+11];
		if (sum>2*x){
			ans++;
		}
		sum=0;
	}
	long long MOD=998244353;
	cout << ans%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
