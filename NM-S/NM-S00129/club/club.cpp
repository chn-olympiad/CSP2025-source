#include<bits/stdc++.h>
using namespace std;
int m(int a,int b,int c){
	if(a>=b&&a>=c) return 1;
	if(b>=a&&b>=c) return 2;
	else return 3;
}
int back(int a){
	if(a==4||a==5) a-=3;return a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int owe;cin>>owe;
    for(int q=0;q<owe;q++){
    	int p[100002][4];//p[][0]选了哪个项目，p[][1,2,3]各个项目的满意度 
		int n;cin>>n;
		int ans=0;
		int pop[4];pop[1]=0;pop[2]=0;pop[3]=0;
    	for(int i=0;i<n;i++){
    		for(int j=1;j<=3;j++){
    			cin>>p[i][j];
			}
		}
		for(int i=0;i<n;i++){
			int high=m(p[i][1],p[i][2],p[i][3]);
			pop[high]++;
			ans+=p[i][high];
			p[i][0]=high;
			if(pop[high]>n/2){
				int maxScore=-100000;
				int m[2];//成员，项目 
				for(int j=0;j<=i;j++){
					if(p[j][0]==high){
						if(p[j][back(high+1)]-p[j][high]>maxScore){
							maxScore=p[j][back(high+1)]-p[j][high];
							m[0]=j;m[1]=back(high+1);
						}
						if(p[j][back(high+2)]-p[j][high]>maxScore){
							maxScore=p[j][back(high+2)]-p[j][high];
							m[0]=j;m[1]=back(high+2);
						}
					}
				}
				p[m[0]][0]=m[1];ans+=maxScore;pop[high]--;
			}
			
		}
		cout<<ans<<"\n";
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
