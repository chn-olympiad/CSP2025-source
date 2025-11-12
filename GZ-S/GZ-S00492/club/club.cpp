//GZ-S00492 贵州省实验中学 韩一鸣
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in",'r',stdin);
	freopen("club.out",'w',stdout);
	int n;
	cin>>n;
	int sum[n]={0};
	for(int l=0;l<n;l++){
		int m=0,a=0,s=0,d=0;
		bool f=1;
		cin>>m;
		int y[m+5][3],r[m+5][2],p[m];
		for(int i=0;i<m;i++){
			cin>>y[i][0]>>y[i][1]>>y[i][2];
			if (y[i][1]!=0 || y[i][2]!=0){
				f=0;
			}
			if(y[i][0]>=y[i][1] && y[i][0]>=y[i][2]){
				r[i][0]=y[i][0];
				p[i]=y[i][0];
				r[i][1]=1;
				a++;
			}else{
				if(y[i][1]>=y[i][0] && y[i][1]>=y[i][2]){
					r[i][0]=y[i][1];
					p[i]=y[i][1];
				r[i][1]=2;
				s++;
			}else{
				r[i][0]=y[i][2];
				p[i]=y[i][2];
				r[i][1]=3;
				d++;
			}
			}
		}
		sort(p,p+m);
		if(f){
		for(int i=m-1;i>=m/2;i--){
			sum[l]+=p[i];
		}
		continue;
		}
		for (int i=0;i<m;i++){
			sum[l]+=r[i][0];
		}
	}
	for (int i=0;i<n;i++){
		cout<<sum[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
