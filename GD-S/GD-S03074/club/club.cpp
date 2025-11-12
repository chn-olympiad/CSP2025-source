#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	int numb,m;
	cin>>numb;
	for(int i=0;i<numb;i++){
		int c1,c2,c3,n1=0,n2=0,n3=0;
		int t1,t2,t3,ma=0,fm;
		int all=0;
		cin>>m;
		int club1[m/2][3],club2[m/2][3],club3[m/2][3];
		for(int j=0;j<m;j++){
			ma=0;
			cin>>c1>>c2>>c3;
			if(c1>=c2&&c1>=c3&&n1<m/2){
				club1[n1][0]=c1;
				club1[n1][1]=c2;
				club1[n1++][2]=c3;
			}else if(c3>=c2&&c3>=c1&&n3<m/2){
				club3[n3][0]=c1;
				club3[n3][1]=c2;
				club3[n3++][2]=c3;
			}else if(c2>=c1&&c2>=c3&&n2<m/2){
				club2[n2][0]=c1;
				club2[n2][1]=c2;
				club2[n2++][2]=c3;
			}else if(c1>=c2&&c1>=c3){
				for(int z=0;z<m/2;z++){
					if((c1-max(c2,c3))-(club1[z][0]-max(club1[z][1],club1[z][2]))>ma){
						ma=(c1-max(c2,c3))-(club1[z][0]-max(club1[z][1],club1[z][2]));
						fm=z;
					}
				}
				if(ma>0){

					t1=club1[fm][0];
					t2=club1[fm][1];
					t3=club1[fm][2];
					club1[fm][0]=c1;
					club1[fm][1]=c2;
					club1[fm][2]=c3;
					if(club1[n1][1]>club1[n1][2]){
						club2[n2][0]=t1;
						club2[n2][1]=t2;
						club2[n2++][2]=t3;
						
					}else{
						club3[n3][0]=t1;
						club3[n3][1]=t2;
						club3[n3++][2]=t3;
					}
				}
			}else if(c2>=c1&&c2>=c3){
				for(int z=0;z<m/2;z++){
					if((c2-max(c3,c1))-(club2[z][1]-max(club2[z][0],club2[z][2]))>ma){
						ma=(c2-max(c1,c3))-(club2[z][1]-max(club2[z][0],club2[z][2]));
						fm=z;
					}
				}
			
				if(ma>0){

					t1=club2[fm][0];
					t2=club2[fm][1];
					t3=club2[fm][2];
					club2[fm][0]=c1;
					club2[fm][1]=c2;
					club2[fm][2]=c3;
					if(club2[n2][0]>club2[n2][2]){
						club1[n1][0]=t1;
						club1[n1][1]=t2;
						club1[n1++][2]=t3;
					}else{
						club3[n3][0]=t1;
						club3[n3][1]=t2;
						club3[n3++][2]=t3;
					}
				}
			}else{
				for(int z=0;z<m/2;z++){
					if((c3-max(c2,c1))-(club3[z][2]-max(club3[z][0],club3[z][1]))>ma){
						ma=(c3-max(c1,c2))-(club3[z][2]-max(club3[z][0],club3[z][1]));
						fm=z;
					}
				}
			
				if(ma>0){

					t1=club3[fm][0];
					t2=club3[fm][1];
					t3=club3[fm][2];
					club3[fm][0]=c1;
					club3[fm][1]=c2;
					club3[fm][2]=c3;
					if(club3[n3][0]>club3[n3][1]){
						club1[n1][0]=t1;
						club1[n1][1]=t2;
						club1[n1++][2]=t3;
					}else{
						club2[n2][0]=t1;
						club2[n2][1]=t2;
						club2[n2++][2]=t3;
					}
				}
			}
		}
		for(int j=0;j<n1;j++){
			all=all+club1[j][0];
		}
		for(int j=0;j<n2;j++){
			all=all+club2[j][1];;
		}
		for(int j=0;j<n3;j++){
			all=all+club3[j][2];;
		}
		cout<<all<<" ";
		cout<<endl;
		n1=n2=n3=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
