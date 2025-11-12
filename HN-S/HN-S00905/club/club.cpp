#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int n,num=0,sum=0,ac=0,bc=0,cc=0;
		char u='0';
		cin>>n;
		for (int i = 1;i <= n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for (int i = 1;i <= n;i++){
			if ((a[i] == 0 && b[i] == 0) || (b[i] == 0 && c[i] == 0) || (a[i] == 0 && c[i] == 0)){
				if(a[i] > num){
					num=a[i];
					u='a';
				}else if (b[i] > num){
					num=b[i];
					u='b';
				}else if (c[i] > num){
					num=c[i];
					u='c';
				}
			}
		}
		sum+=num;
		if (u == 'a'){
			ac++;
			if (ac == n/2){
				a[1]=a[2];
			}
		}else if (u == 'b'){
			bc++;
			if (bc == n/2){
				b[1]=b[2];
			}
		}else if (u == 'c'){
			cc++;
			if (cc == n/2){
				c[1]=c[2];
			}
		}
		a[num]=b[num]=c[num]=0;
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		for (int i = n;i >= 1;i--){
			if (ac < n/2 && ac+bc+cc != n){
				sum+=a[i];
				ac++;
			}
			if (bc < n/2 && ac+bc+cc != n){
				sum+=b[i];
				bc++;
			}
			if (cc < n/2 && ac+bc+cc != n){
				sum+=c[i];
				cc++;
			}
			if (ac+bc+cc == n){
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
