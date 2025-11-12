#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n,sum=0;
		cin >> n;
		long long a[n],b[n],c[n],q=0,w=0,e=0,x[10001]={0};
		for(int i=1;i<=n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				sum+=a[i];
				x[i]+=a[i];
				q++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				sum+=b[i];
				x[i]+=b[i];
				w++;
			}else if(c[i]>=b[i]&&c[i]>=a[i]){
				sum+=c[i];
				x[i]+=c[i];
				e++;
			}
			
			if(a[i]>=b[i]&&a[i]<=c[i]){
				x[i]-=a[i];
			}else if(b[i]>=a[i]&&b[i]<=c[i]){
				x[i]-=b[i];
			}else if(c[i]>=b[i]&&c[i]<=a[i]){
				x[i]-=c[i];
			}else if(a[i]<=b[i]&&a[i]>=c[i]){
				x[i]-=a[i];
			}else if(b[i]<=a[i]&&b[i]>=c[i]){
				x[i]-=b[i];
			}else if(c[i]<=b[i]&&c[i]>=a[i]){
				x[i]-=c[i];
			}
		}
		if(q<n/2&&w<n/2&&e<n/2){
		}else if(q>(n/2)){
			sort(x,x+n+1);
			while(q>(n/2)){
				sum-=x[1];
				for(int i=1;i<=n;i++){
					x[i]=x[i+1];
				}
				q--;
			}
		}else if(w>(n/2)){
			sort(x,x+n+1);
			cout << x[1]<<x[2]<<x[3]<<x[4];
			while(w>(n/2)){
				sum-=x[1];
				for(int i=1;i<=n;i++){
					x[i]=x[i+1];
				}
				w--;
			}
		}else{
			sort(x,x+n+1);
		while(e>(n/2)){
			sum-=x[1];
			for(int i=1;i<=n;i++){
					x[i]=x[i+1];
				}
			e--;
		}
	}
		cout << sum << endl;
	}
	return 0;
}
