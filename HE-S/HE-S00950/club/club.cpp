#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id1,id2,num;
}b[100005];

bool cmp(node a,node b){
	if(a.num!=b.num) return a.num>b.num; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	
	while(T--){
		int n;
		cin>>n;
		int sum = 0;
		vector<vector<int> > a(n,vector<int>(3,0));
		for(int i=0;i<n;i++){
			int max = -1;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(max<a[i][j]){
					max=a[i][j];
					b[i].id1 = i;
					b[i].id2 = j;
					b[i].num = max;
				}
			}
		}
		int m = 1;
		for(int i=0;i<n-1;i++){
			if(b[i].id2 == b[i+1].id2){
				m++;
			}
		}
		if(m<=n/2){
			for(int i=0;i<n;i++){
				sum+=b[i].num;
			}
			cout<<sum;
		}else if (m>n/2){
			sort(b,b+n,cmp);
			int max = -1;
			while(m>n/2){
				int l,r;
				for(int i=0;i<n;i++){
					for(int j=0;j<3;j++){
						if(a[i][j]==b[i].num) continue;
						if(max<a[i][j]){
							max=a[i][j];
							l = i;
							r = j;
						}
					}
				}
				b[l].id1 = l;
				b[l].id2 = r;
				b[l].num = max;
				max = -1;
				m--;
			}
			for(int i=0;i<n;i++){
				sum+=b[i].num;
			}
			cout<<sum;
		}
	}
	return 0;
} 
