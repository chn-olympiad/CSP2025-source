#include<iostream>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int timellp = 0;
	cin>>timellp;
	while(timellp){
		timellp--;
		//main
		int n =0;
		cin>>n;
		int MaxMember = n/2;
		int s[50005][3] = {0};
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
		}
//		for(int i=0;i<n;i++){
//			cout<<s[i][0]<<' '<<s[i][1]<<' '<<s[i][2]<<endl;
//		}
//		return 0;
		int dp[50005] = {};
		dp[0] = 0;
		int a=0,b=0,c=0;
		int p=0;
		for(int i=1;i<=n;i++){
			int t = 0;
			if(a<MaxMember){
				if(dp[i-1]+s[i][0]>t){
					p=1;//gx a a++
					t=dp[i-1]+s[i][0];
				}
			}else{
				if(b<MaxMember){
					for(int q = 1;q<=i;q++){
						if(dp[i-1]-s[q][0]+s[q][1]+s[i][0] >t){
							p=2;//b++ gx a zj b nimi
							t=dp[i-1]-s[q][0]+s[q][1]+s[i][0];
						}	
					}
					
				}else{
					for(int q = 1;q<=i;q++){
					if(dp[i-1]-s[q][0]+s[q][2]+s[i][0] > t){
						p=3;//c++ gx a zj c mini
						t=dp[i-1]-s[q][0]+s[q][2]+s[i][0];
					}
				}
				}
			}
		if(b<MaxMember){
				if(dp[i-1]+s[i][1]>t){
					p=4;//gx b b++
					t=dp[i-1]+s[i][1];
				}
			}else{
				if(a<MaxMember){
					for(int q = 1;q<=i;q++){
					if(dp[i-1]-s[q][1]+s[q][0]+s[i][1] > t){
						p=5;//a++ gx b zj a mini
						t=dp[i-1]-s[q][1]+s[q][0]+s[i][1];
					}
				}
				}else{
					for(int q = 1;q<=i;q++){
					if(dp[i-1]-s[q][1]+s[q][2]+s[i][1] > t){
						p=6;//c++ gx b zj c mini
						t=dp[i-1]-s[q][1]+s[q][2]+s[i][1];
					}
				}
				}
			}if(c<MaxMember){
				if(dp[i-1]+s[i][0]>t){
					p=7;//gx c c++
					t=dp[i-1]+s[i][2];
				}
			}else{
				if(b<MaxMember){
					for(int q = 1;q<=i;q++){
					if(dp[i-1]-s[q][2]+s[q][1]+s[i][2] > t){
						p=8;//b++ gx c zj b nimi
						t=dp[i-1]-s[q][2]+s[q][1]+s[i][2];
					}
				}
				}else{
					for(int q = 1;q<=i;q++){
					if(dp[i-1]-s[q][2]+s[q][0]+s[i][2] > t){
						p=9;//a++ gx c zj a mini
						t=dp[i-1]-s[q][2]+s[q][0]+s[i][2];
					}
				}
				}
			}
			if(p==1){
				a++;
				//cout<<"放进a中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==2){
				b++;
				//cout<<"放进a中，把a的最小值取出来放进b中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==3){
				c++;
				//cout<<"放进a中，把a的最小值取出来放进v中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==4){
				b++;
				//cout<<"放进b中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==5){
				a++;
				//cout<<"放进b中，把b的最小值取出来放进a中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==6){
				c++;
			//	cout<<"放进b中，把b的最小值取出来放进c中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==7){
				c++;
			//	cout<<"放进c中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==8){
				b++;
			//	cout<<"放进c中，把c的最小值取出来放进b中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}else if(p==9){
				a++;
					//cout<<"放进c中，把c的最小值取出来放进a中:"<<t<<"增加了"<<t - dp[i-1]<<endl;
			}
			dp[i] = t;
	}
	cout<<dp[n];
	cout<<endl;
}
	return 0;
}
