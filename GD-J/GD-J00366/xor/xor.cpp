#include<bits/stdc++.h>
using namespace std;
struct data1{
	long long s,e;
}arr[10001];
long long n,k,a[10001],ans,cnt=1,e;
bool check(long l,long r){
	long long sum=a[l]; 
	for(long long i=l+1;i<r;i++){
		sum^=a[i];
	}
	return sum==k;
}
bool cmp(data1 a,data1 b){
	return a.e<b.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)){
				arr[cnt++].s=i;
				arr[cnt++].e=j;
				break;
			}
		}
	}
	sort(arr+1,arr+cnt,cmp);
	if(cnt>1){
		ans++;
		e = arr[1].e;
	}else{
		cout << 0;
		return 0;
	}
	for(int i=2;i<=cnt;i++){
		if(e<arr[i].s){ 
			e = arr[i].e;
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
