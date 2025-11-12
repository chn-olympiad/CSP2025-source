#include<bits/stdc++.h>
using namespace std;
int mm[5010],cnm;
int cs1(int sd1,int sm1,int sqj1){
	if(sd1>=sm1){
		if(sd1<sqj1) return sqj1;
		else return sd1; 
	}
	if(sm1>=sd1){
		if(sm1<sqj1) return sqj1;
		else return sm1; 
	}
}
int cs2(int sd2,int sm2,int sqj2,int sg2){
	if(sd2>=sm2){
		if(sd2>=sqj2){
			if(sd2>=sg2) return sd2;
			else return sg2;
		}
		else{
			if(sqj2>=sg2) return sqj2;
			else return sg2;
		}
	}
	else{
		if(sm2>=sqj2){
			if(sm2>=sg2) return sm2;
			else return sg2;
		}
		else{
			if(sqj2>=sg2) return sqj2;
			else return sg2;
		}
	}
}
int cs3(int sd3,int sm3,int sqj3,int sg3,int qs3){
	if(sd3>=sm3){
		if(sd3>=sqj3){
			if(sd3>=sg3){
				if(sd3>qs3) return sd3;
				else return qs3;
			}
			else{
				if(sg3>qs3) return sg3;
				else return qs3;
			}
		}
		else{
			if(sqj3>=sg3){
				if(sqj3>qs3) return sqj3;
				else return qs3;
			}
			else{
				if(sg3>qs3) return sg3;
				else return qs3;
			}
		}
	}
	else{
		if(sm3>=sqj3){
			if(sm3>=sg3){
				if(sm3>qs3) return sm3;
				else return qs3;
			}
			else{
				if(sg3>qs3) return sg3;
				else return qs3;
			}
		}
		else{
			if(sqj3>=sg3){
				if(sqj3>qs3) return sqj3;
				else return qs3;
			}
			else{
				if(sg3>qs3) return sg3;
				else return qs3;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ctm=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mm[i];
	}
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				ctm=cs1(mm[i],mm[j],mm[k]);
				if((mm[i]+mm[j]+mm[k])>ctm*2){
					cnm++;
				}
			}
		}
	}
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int l=1;l<k;l++){
					ctm=cs2(mm[i],mm[j],mm[k],mm[l]);
					if((mm[i]+mm[j]+mm[k]+mm[l])>ctm*2){
						cnm++;
					}
				}
			}
		}
	}
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				for(int l=1;l<k;l++){
					for(int t=1;t<l;t++){
						ctm=cs3(mm[i],mm[j],mm[k],mm[l],mm[t]);
						if((mm[i]+mm[j]+mm[k]+mm[l]+mm[t])>ctm*2){
							cnm++;
						}
					}
				}
			}
		}
	}
	cout<<cnm;
	return 0;
}
