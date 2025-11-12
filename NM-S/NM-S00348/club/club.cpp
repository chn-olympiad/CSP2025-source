#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

	int t = 0;
	int n = 0;
	int max = 0;
	int club1 = 0;
	int club2 = 0;
	int club3 = 0;
	int ren[3] = {};
	int jie[] = {};

	cin>>t;
	for(int a=0;a<t;a++) {
		cin>>n;
		for(int b=1;b<=n;b++){
			for(int c=0;c<3;c++){
				cin>>ren[c];
			}
			if(ren[0]>=ren[1] && ren[0]>=ren[2]){
				if(club1 >= n/2){
					if(ren[1]>=ren[2]){
						max = ren[1] + max;
						club2 = club2 + 1;
					}
					else{
						max = ren[2] + max;
						club3 = club3 + 1;
					}
				}
				else{
					club1 = club1 + 1;
					max = ren[0] + max;
				}
			}
			if(ren[1]>=ren[0] && ren[1]>=ren[2]){
				if(club2 >= n/2){
					if(ren[0]>=ren[2]){
						max = ren[0] + max;
						club1 = club1 + 1;
					}
					else{
						max = ren[2] + max;
						club3 = club3 + 1;
					}
				}
				else{
					club2 = club2 + 1;
					max = ren[1] + max;
				}
			}
			if(ren[2]>=ren[0] && ren[2]>=ren[1]){
				if(club3 >= n/2){
					if(ren[0]>=ren[1]){
						max = ren[0] + max;
						club1 = club1 + 1;
					}
					else{
						max = ren[1] + max;
						club2 = club2 + 1;
					}
				}
				else{
					club3 = club3 + 1;
					max = ren[2] + max;
				}
			}
			cout<<max<<endl;
			cout<<club1<<club2<<club3;
		}
		jie[a] = max;
		max = 0;
		club1 = 0;
		club2 = 0;
		club3 = 0;
	}
	for(int d=0;d<t;d++){
		cout<<jie[d]<<endl;
	}
	return 0;
}
