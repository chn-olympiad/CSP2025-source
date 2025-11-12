#include<bits/stdc++.h>
using namespace std;
struct nums{
	long long val;
	bool used=false;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	vector<nums> num(n);
	for(int i=1;i<=n;i++)cin>>num[i].val;
	for(long length=1;length<=n;length++){
		for(long pos=1;pos<=n-length+1;pos++){
			int v=0;
			if(num[pos].val==k&&num[pos].used==false){
				num[pos].used=true;
				sum++;
				continue;
			}
			for(int r=pos;r<pos+length;r++){
				if(num[r].used==false){
					v^=num[r].val;
				}else{
					break;
				}
			}
			if(v==k){
				for(int r=pos;r<pos+length;r++){
					if(num[r].used==true)sum--;
					num[r].used=true;
				}
				sum++;
			}
		}
	}
	cout<<sum;
}
