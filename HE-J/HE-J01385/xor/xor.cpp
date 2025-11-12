#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	int a[n];
	int sum=0;
	int num=0;
	int z;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			a[i]=-1;
			sum++;
			num=0;
			int d=0;
		}else if(a[i]!=-1&&num!=0){
			int b=a[i];
			int bb=num;
			vector<int> c1;
			vector<int> c2;
			vector<int> c3;
			int d=0;
			while(b>0){
				c1.push_back(b%2);
				b/=2;
			}
			while(bb>0){
				c2.push_back(bb%2);
				bb/=2;
			}
			for(int j=0;j<c1.size()&&j<c2.size();j++){
				if(c1[j]==c2[j]&&c1[j]==1){
					c3.push_back(0);
				}else{
					c3.push_back(1);
				}
			}
			if(c1.size()>c2.size()){
				for(int j=c2.size();j<c1.size();j++){
					c3.push_back(c1[j]);
				}
			}else if(c1.size()<c2.size()){
				for(int j=c1.size();j<c2.size();j++){
					c3.push_back(c2[j]);
				}
			}
			for(int j=c3.size()-1;j>=0;j--){
				d*=2;
				d+=c3[j];
			}
			num=d;
			if(num>k){
				i=z+1;
				a[z]=-1;
				num=0;
				d=0;
			}else if(num==k){
				for(int j=z;j<i;j++){
					a[j]=-1;
				}
				num=0;
				d=0;
				sum++;
			}
		}else if(a[i]!=-1&&num==0){
			z=i;
			num=a[i];
			a[i]=-1;
		} 
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}