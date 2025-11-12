#include<iostream>
using namespace std;
int t;
int n;
int aa[4];
struct club {
	int bh,an[4],gs;
};
club a[100005];
int px(int nx) { //冒泡排序
	//对第nx组进行排序
	for(int i=n; i>=1; i--) {
		for(int j=n; j>=2; j--) {
			if(a[j].an[nx]>a[j-1].an[nx]) {
				club s=a[j];
				a[j]=a[j-1];
				a[j-1]=s;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cout<<a[i].an[j]<<' ';
		}
		cout<<endl;
	}*/
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ti=1; ti<=t; ti++) {
		aa[1]=0;aa[2]=0;aa[3]=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			int i1,i2,i3;
			cin>>i1>>i2>>i3;
			a[i].bh=i;
			a[i].gs=0;
			a[i].an[1]=i1;
			a[i].an[2]=i2;
			a[i].an[3]=i3;
		}
		for(int kl=0;kl<=10;kl++) {
			for(int i=1; i<=3; i++) { //第i个社团的最大满意度
				px(i);
				if(aa[i]<n/2) {
					for(int j=1; j<=n; j++) {
						if(a[j].gs!=0&&a[j].gs!=i) { //占用冲突
							int maxi=i;
							for(int k=1; k<=3; k++) { //是否利益最大？
								if(a[j].an[k]>a[j].an[i]) {
									maxi=k;
								}
							}
							if(maxi==i) { //利益最大
								aa[a[j].gs]--;
								a[j].gs=maxi;
								aa[maxi]++;
								//cout<<"新人"<<a[j].bh<<"转移到"<<maxi<<"组织"<<endl;
							}
						} else {
							if(a[j].gs==0&&aa[i]<n/2){
								aa[i]++;
							a[j].gs=i;
							//cout<<"新人"<<a[j].bh<<"加入"<<i<<"组织"<<"人数："<<aa[i]<<endl;
							}
							
						}
					}
				}
			}
			/*for(int jn=1; jn<=n; jn++) {
				for(int in=1; in<=n; in++) {
					if(a[in].bh==jn) {
						cout<<a[in].gs<<' ';
					}
				}
			}
			cout<<endl;*/
		}
		long ans=0;
		for(int j=1; j<=n; j++) {
			ans+=a[j].an[a[j].gs];
		}
		cout<<ans<<endl;
	}
	return 0;
}
