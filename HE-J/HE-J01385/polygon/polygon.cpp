#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int num=0,sum=0;
	sort(a,a+n);
	int m=-1;
	int aa[100][5000];
	int z=0;
	while(m<n){
		for(int i=0;i<n;i++){
			vector<int> o;
			if(i==m){
				continue;
			}
			num=a[i];
			o.push_back(i);
			for(int j=i+1;j<n;j++){
				if(j==m){
					continue;
				}
				num+=a[j];
				o.push_back(j);
				if(num>a[j]*2){
					bool b=1;
					for(int ii=0;ii<z;ii++){
						bool bb=0;
						for(int jj=0;jj<o.size();jj++){
							if(aa[ii][jj]!=o[jj]){
								bb=1;
								break;
							}
						}
						if(bb==0){
							b=0;
							break;
						}
					}
					if(b){
						for(int k=0;k<o.size();k++){
							aa[z][k]=o[k];
						}
						z++;
						sum++;
					}
				}
			}
		}
		m++;
	}
	cout<<sum%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
