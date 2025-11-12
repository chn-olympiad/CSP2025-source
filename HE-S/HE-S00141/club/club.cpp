#include<bits/stdc++.h>

using namespace std;
	int t;
	int s[6];
	int n;
    int zs=0;
    int neirong1=0,neirong2=0,neirong3=0;
class aaa{
	public:
		int a1;
		int a2;
		int a3;
	};
	aaa ren[100101];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		zs=0;
		for(int j=0;j<n;j++){
			cin>>ren[j].a1;
			cin>>ren[j].a2;
			cin>>ren[j].a3;
		}
		int manyi_1[n];
		int manyi_2[n];
		int manyi_3[n];
		for(int j=0;j<n;j++){
			if(ren[j].a1>=ren[j].a2&&ren[j].a1>=ren[j].a3){
				if(neirong1<n/2){
			    zs+=ren[j].a1;
			    neirong1++;
				}
				else if(ren[j].a2>=ren[j].a2){
					zs+=ren[j].a2;
				}
				else{
					zs+=ren[j].a3;
				}
			}
			else if(ren[j].a2>=ren[j].a1&&ren[j].a2>=ren[j].a3){
			   	if(neirong2<n/2){
			    zs+=ren[j].a2;
			    neirong2++;
				}
				else if(ren[j].a1>=ren[j].a3){
					zs+=ren[j].a1;
				}
				else{
					zs+=ren[j].a3;
				}
			}
			else if(ren[j].a3>=ren[j].a2&&ren[j].a3>=ren[j].a1){
				if(neirong3<n/2){
				zs+=ren[j].a3;
				neirong3++;
				}
				else if(ren[j].a1>=ren[j].a2){
					zs+=ren[j].a1;
				}
				else{
					zs+=ren[j].a2;
				}
			}
		}
        cout<<zs<<endl;
	}
	return 0;
}
