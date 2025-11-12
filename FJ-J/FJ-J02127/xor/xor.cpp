#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
long long k,sum=0;
bool l[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long b;
	bool p;
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			b=0;
			for(int j=i;j<=o;j++){
				p=true;
				b=b^a[j];
				if(b==k){
				for(int h=i;h<=j;h++){
					if(l[h]){
						p=false;
						break;
					}
				}
				if(p){
					for(int h=i;h<=j;h++) l[h]=true;
					sum++;
				}
				}
			}
		}
	}
	cout<<sum<<endl;
	/*
	毒瘤出题人
	把数据设这么大
	我把WA改成了TLE 
	QAQ
	*/
	return 0;
}
