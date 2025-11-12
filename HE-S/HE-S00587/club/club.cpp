#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T,n,m,cnt;
int a[MAXN],b[MAXN],c[MAXN];
int cnt_a,cnt_b,cnt_c;
int num_a[MAXN],num_b[MAXN],num_c[MAXN];
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt_a=0;
		cnt_b=0;
		cnt_c=0;
		sum=0;
		memset(num_a,0,sizeof(num_a));
		memset(num_b,0,sizeof(num_b));
		memset(num_c,0,sizeof(num_c));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]){
				if(a[i]>c[i]){
					sum+=a[i];
					cnt_a++;
					num_a[cnt_a]=a[i]-max(b[i],c[i]);
				}else{
					sum+=c[i];
					cnt_c++;
					num_c[cnt_c]=c[i]-a[i];
				}
			}
			else{
				if(b[i]>c[i]){
					sum+=b[i];
					cnt_b++;
					num_b[cnt_b]=b[i]-max(a[i],c[i]);
				}else{
					sum+=c[i];
					cnt_c++;
					num_c[cnt_c]=c[i]-b[i];
				}
			}
		}
		sort(num_a+1,num_a+cnt_a+1);
		sort(num_b+1,num_b+cnt_b+1);
		sort(num_c+1,num_c+cnt_c+1);
		if(cnt_a>cnt_b){
			if(cnt_a>cnt_c){
				cnt=1;
				m=cnt_a;
			}else{
				cnt=3;
				m=cnt_c;
			}
		}
		else{
			if(cnt_b>cnt_c){
				cnt=2;
				m=cnt_b;
			}else{
				cnt=3;
				m=cnt_c;
			}
		}
		if(m<=n/2){
			cout<<sum<<"\n";
		}else{
			int j=1;
			for(int i=m;i>n/2;i--){
				if(cnt==1){
					sum-=num_a[j];
					j++;
				}
				if(cnt==2){
					sum-=num_b[j];
					j++;
				}
				if(cnt==3){
					sum-=num_c[j];
					j++;
				}
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}
