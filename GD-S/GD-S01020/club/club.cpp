#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n;
		cin>>n;
		long long max_enjoyment=-1;//最佳满意度 
		long long max_club_menber=t/2;//社团最大招收成员 
		long long every_club_menber[4]={};//每个社团现在的人数 
		long long personal_enjoyment[n+2][n+2]={};//个人对每个社团的满意度 
		for(int j=1;j<=n;j++){
			for(int l=1;l<=3;l++){
				cin>>personal_enjoyment[j][l];
			}
		}//输入 
		for(int j=1;j<=3;j++){
			
			while(every_club_menber[j]<max_club_menber){
				long long max=-1;
				long long max_person=0;
				for(int x=1;x<=n;x++){
					if(personal_enjoyment[x][j]>max){
						max=personal_enjoyment[x][j];
						max_person=x;
					}
				}
				max_enjoyment+=max;
				personal_enjoyment[max_person][j]=0;
				every_club_menber[j]++;
			}	
			
		}
		
		cout << max_enjoyment<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
