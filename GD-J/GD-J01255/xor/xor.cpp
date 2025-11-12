#include<bits/stdc++.h>
using namespace std;
long long a[500001];
struct bruh{
	int start;
	int end;
}br[500001];
bool cmp(bruh x,bruh y){
	return x.end<y.end;
}
bool b[500001];
int cur=0;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long ans=a[i];
			for(int k=i+1;k<=j;k++){
				ans=ans^a[k];
			}
			if(ans==m){
				cur++;
				br[cur].start=i;
				br[cur].end=j;
			}
		}
	}
	sort(br+1,br+cur+1,cmp);
    int ys=0;
    for(int i=1;i<=cur;i++){
    	bool k=1;
    	for(int j=br[i].start;j<=br[i].end;j++){
    		if(b[j]==1){
    			k=0;
    			break;
			}
		}
		if(!k) continue;
    	for(int j=br[i].start;j<=br[i].end;j++) b[j]=1;
		ys++; 
		//²âÊÔcout<<br[i].start<<" "<<br[i].end<<endl;
	}
	cout<<ys<<endl;
	return 0;
}
