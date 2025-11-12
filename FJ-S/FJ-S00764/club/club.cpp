#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		int m,l = 0;
		cin>>m;
		int club1[m],club2[m],club3[m],max[m];
		for(int j=0;j<m;j++){
			cin>>club1[j]>>club2[j]>>club3[j];
			if(club1[j]>club2[j] && club1[j]>club3[j]){
				max[j] = club1[j];
				club1[j] = 0;
			}if(club2[j]>club3[j] && club2[j]>club1[j]){
				max[j] = club2[j];
			}if(club3[j]>club1[j] && club3[j]>club2[j]){
				max[j] = club3[j];
			}
		}		
		for(int i = 0;i <n;i++){
			l+=max[i];
		}
		cout<<l<<endl;
	}
	return 0;
}

