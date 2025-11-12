#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in",'r',stdin);
	//freopen("club.out",'w',stdout);
	
	int da;
	cin>>da;
	while(da--){
		int x,countt = 0,countt1 = 0,countt2 = 0;
		cin>>x;
		int a[100001][3];
		for(int i = 0;i < x;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int s1[3] = {0,0,0};
		for(int i = 0;i < x;i++){
			int maxxx = 0,maxx = 0,sj = 0;
			int maxxx1 = 0,maxx1 = 0,sj1 = 0;
			int maxxx2 = 0,maxx2 = 0,sj2 = 0;
			for(int z = 0;z < x;z++){
				for(int j =0;j <= 2;j++){
					if(a[z][j]>maxxx&&s1[j]<=x/2){
						//cout<<s1[j];
						
						maxxx = a[z][j];
						maxx = z;
						sj = j;
					}
				}
			}
			countt+=maxxx;
			s1[sj]+=1;
			a[maxx][0] = a[maxx][1] = a[maxx][2] = 0;
			
		}
		cout<<countt<<endl;
	}
	
	
	
	
	return 0;
	//fclose(stdin);
	//fclose(stdout);

} 
