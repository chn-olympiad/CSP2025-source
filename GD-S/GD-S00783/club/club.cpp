#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long t;
	cin>>t;
	while(t--){
		
	
		long long  n;
		cin>>n;
		int zhao=n/2;
		int xue[3]={0,0,0};
		vector<vector<int> > a(n,vector<int> (3,0));
		for(long long i=0;i<n;i++){
			for(long long j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		long long sum=0;
		for(long long i=0;i<n;i++){//先加最大的 
			long long  qu=0;
			long long maxx=0;
			for(long long j=0;j<3;j++){
				if(a[i][j]>maxx){
					maxx=a[i][j];
					qu=j;
				}
			}
			xue[qu]+=1;
			sum+=a[i][qu];
		}
//		for(int i=0;i<3;i++){
//			if(xue[i]>zhao){
//				for(int j=0;j<n;j++){
//					if(sum-a[j][i])
//				}
//			}
//		}
		for(long long i=0;i<3;i++){//保证每个部门不大于n/2 
			if(xue[i]>zhao){
				long long m=xue[i]-zhao;
				while(m--){
					int minx=INT_MAX;
					int chu=0;
					for(int j=0;j<n;j++){
						if(minx>a[j][i]){
						minx=a[j][i];
						chu=j;
						} 
						int o1=INT_MAX,o3=0;
						int s1=0,s2=0,s3=0;
						for(int x=0;x<3;x++){
							if(o1>a[chu][x]){
							o1=a[chu][x];
							s1=x;
							}
							if(o3<a[chu][x]){
							o3=a[chu][x];
							s3=x;
							}
						}
						s2=3-s3-s1;
						if(xue[s2]<zhao){
							xue[i]--;
							xue[s2]++;
							sum-=a[chu][i];
							sum+=a[chu][s2];
						}else{
							xue[i]--;
							xue[s3]++;
							sum-=a[chu][i];
							sum+=a[chu][s3];
						}	
					}
				}
				
			}else continue;
		}
		cout<<sum<<endl;
	}
	cout<<flush;
	return 0;
}
