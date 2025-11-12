#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	
	int t,n,ai_1,ai_2,ai_3,ans_1=0,ans_2=0,ans_3=0,a;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>ai_1>>ai_2>>ai_3;
		}
		if(ai_1>ai_2&&ai_1>ai_3){
			if(ans_1=n/2-1){
				if(ans_2=n/2-1){
					if(ans_3=n/2-1){
						a=0;
					}else{
						ans_3++;
						a=ai_3;
					}
				}else{
					ans_2++;
					a=ai_2;
				}
			}else{
				ans_1++;
				a=ai_1;
			}
		}else if(ai_2>ai_1&&ai_2>ai_3){
			if(ans_2=n/2-1){
				if(ans_3=n/2-1){
					if(ans_1=n/2-1){
						a=a+0;
					}else{
						ans_1++;
						a=a+ai_1;
					}
				}else{
					ans_3++;
					a=a+ai_3;
				}
			}else{
				ans_2++;
				a=a+ai_2;
			}
		}else{
			if(ans_3=n/2-1){
				if(ans_2=n/2-1){
					if(ans_1=n/2-1){
						a=a+0;
					}else{
						ans_1++;
						a=a+ai_1;
					}
				}else{
					ans_2++;
					a=a+ai_2;
				}
			}else{
				ans_3++;
				a=a+ai_3;
			}
		}
		cout<<a<<endl;
		ans_1=0;
		ans_2=0;
		ans_3=0;
		a=0;
	}
	return 0;
} 
