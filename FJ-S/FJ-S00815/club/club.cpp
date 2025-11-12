#include <bits/stdc++.h>
using namespace std;
struct people{
	int A1,A2,A3;
	bool A1_flag=false;
	bool A2_flag=false;
	bool A3_flag=false;
}A[100005];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int club_A1=n/2,club_A2=n/2,club_A3=n/2;
		int MAX_A1=0,MAX_A2=0,MAX_A3=0;
		int csp_MAX_A1=0,csp_MAX_A2=0,csp_MAX_A3=0;
		int club_sum=0;
		for(int i=1;i<=n;i++){
			cin>>A[i].A1>>A[i].A2>>A[i].A3;
		}
		int cnt=0;
		while(true){
			if(club_A1>0){
				MAX_A1=0;
				csp_MAX_A1=0;
				for(int i=1;i<=n;i++){
						if(A[i].A1>=MAX_A1 && A[i].A1_flag==false){
						MAX_A1=A[i].A1;
						csp_MAX_A1=i;
					}
				}
				if(MAX_A1!=0) A[csp_MAX_A1].A1_flag=true;
				if(MAX_A1==0) club_A1=0;
				club_A1--;
				cnt++;
				for(int i=1;i<=n;i++){
					if(A[i].A3_flag==true && A[i].A1_flag==true){
						A[i].A3_flag=false;
						A[i].A1_flag=false;
						int AA1=MAX_A1;
						int AA3=MAX_A3;
						int csp2_MAX_A3=0;
						int csp2_MAX_A1=0;
						int csp1_MAX_A3=0;
						int csp1_MAX_A1=0;
						for(int i=1;i<=n;i++){
							if(A[i].A3>=csp2_MAX_A3 && A[i].A2!=AA3){
								csp2_MAX_A3=A[i].A3;
								csp1_MAX_A3=i;
							}
						}
						for(int i=1;i<=n;i++){
							if(A[i].A1>=csp2_MAX_A1 && A[i].A1!=AA1){
								csp2_MAX_A1=A[i].A1;
								csp1_MAX_A1=i;
							}
						}
						if(MAX_A3+csp2_MAX_A1<=MAX_A1+csp2_MAX_A3){
							A[csp1_MAX_A3].A3_flag=true;
							A[csp_MAX_A3].A1_flag=true;
						}else{
							A[csp1_MAX_A1].A1_flag=true;
							A[csp_MAX_A1].A3_flag=true;
						}
					}
				}
			}
			if(club_A2>0){
				MAX_A2=0;
				csp_MAX_A2=0;
				for(int i=1;i<=n;i++){
					if(A[i].A2>=MAX_A2  && A[i].A2_flag==false){
						MAX_A2=A[i].A2;
						csp_MAX_A2=i;
					}
				}
				if(MAX_A2!=0) A[csp_MAX_A2].A2_flag=true;
				if(MAX_A2==0) club_A2=0;
				club_A2--;
				cnt++;
				for(int i=1;i<=n;i++){
					if(A[i].A1_flag==true && A[i].A2_flag==true){
						A[i].A2_flag=false;
						A[i].A1_flag=false;
						int AA2=MAX_A2;
						int AA1=MAX_A1;
						int csp2_MAX_A1=0;
						int csp2_MAX_A2=0;
						int csp1_MAX_A1=0;
						int csp1_MAX_A2=0;
						for(int i=1;i<=n;i++){
							if(A[i].A2>=csp2_MAX_A2 && A[i].A2!=AA2){
								csp2_MAX_A2=A[i].A2;
								csp1_MAX_A2=i;
							}
						}
						for(int i=1;i<=n;i++){
							if(A[i].A1>=csp2_MAX_A1 && A[i].A1!=AA1){
								csp2_MAX_A1=A[i].A1;
								csp1_MAX_A1=i;
							}
						}
						if(MAX_A2+csp2_MAX_A1<=MAX_A1+csp2_MAX_A2){
							A[csp1_MAX_A2].A2_flag=true;
							A[csp_MAX_A2].A1_flag=true;
						}else{
							A[csp1_MAX_A1].A1_flag=true;
							A[csp_MAX_A1].A2_flag=true;
						}
					}
				}
			}
			if(club_A3>0){
				MAX_A3=0;
				csp_MAX_A3=0;
				for(int i=1;i<=n;i++){
					if(A[i].A3>=MAX_A3  && A[i].A3_flag==false){
						MAX_A3=A[i].A3;
						csp_MAX_A3=i;
					}
				}
				if(MAX_A3!=0) A[csp_MAX_A3].A3_flag=true;
				if(MAX_A3==0) club_A3=0;
				club_A3--;
				cnt++;
				for(int i=1;i<=n;i++){
					if(A[i].A3_flag==true && A[i].A2_flag==true){
						A[i].A3_flag=false;
						A[i].A2_flag=false;
						int AA2=MAX_A2;
						int AA3=MAX_A3;
						int csp2_MAX_A3=0;
						int csp2_MAX_A2=0;
						int csp1_MAX_A3=0;
						int csp1_MAX_A2=0;
						for(int i=1;i<=n;i++){
							if(A[i].A2>=csp_MAX_A2 && A[i].A2!=AA2){
								csp2_MAX_A2=A[i].A2;
								csp1_MAX_A2=i;
							}
						}
						for(int i=1;i<=n;i++){
							if(A[i].A3>=csp2_MAX_A3 && A[i].A3!=AA3){
								csp2_MAX_A3=A[i].A3;
								csp1_MAX_A3=i;
							}
						}
						if(MAX_A2+csp2_MAX_A3<=MAX_A3+csp2_MAX_A2){
							A[csp1_MAX_A2].A2_flag=true;
							A[csp_MAX_A2].A3_flag=true;
						}else{
							A[csp1_MAX_A3].A3_flag=true;
							A[csp_MAX_A3].A2_flag=true;
						}
					}
				}
			}
			if(club_A1<=0 && club_A2<=0 && club_A3<=0) break;
		}
		for(int i=1;i<=n;i++){
			if(A[i].A1_flag==true) club_sum+=A[i].A1;
			if(A[i].A2_flag==true) club_sum+=A[i].A2;
			if(A[i].A3_flag==true) club_sum+=A[i].A3;
		}
		cout<<club_sum<<endl;
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
1
2
10 9 8
4 0 0

*/
