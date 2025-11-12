#include<bits/stdc++.h>
using namespace std;
int abc[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum=0;
		int p[3]={0,0,0};
		vector<int> o[3];
		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			abc[i][0]=a;
			abc[i][1]=b;
			abc[i][2]=c;
			int q=0;
			if(a>=b&&a>=c){
				p[0]++;
				q=a;
				o[0].push_back(min(a-b,a-c));
			}
			else if(b>=a&&b>=c){
				p[1]++;
				q=b;
				o[1].push_back(min(b-a,b-c));
			}
			else {
				p[2]++;
				q=c;
				o[2].push_back(min(c-a,c-b));
			}
			sum+=q;
		}
		if(p[0]>n/2){
			sort(o[0].begin(),o[0].end());
			int w=0;
			while(p[0]-w>n/2){
				sum-=o[0][w];
				w++;
			}
			cout<<sum<<endl;
		}
		else if(p[1]>n/2){
			sort(o[1].begin(),o[1].end());
			int w=0;
			while(p[1]-w>n/2){
				sum-=o[1][w];
				w++;
			}
			cout<<sum<<endl;
		}
		else if(p[2]>n/2){
			sort(o[2].begin(),o[2].end());
			int w=0;
			while(p[2]-w>n/2){
				sum-=o[2][w];
				w++;
			}
			cout<<sum<<endl;
		}
		else {
			cout<<sum<<endl;
		}
	}
	return 0;
}
