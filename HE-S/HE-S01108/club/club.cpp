#include<bits/stdc++.h>
using namespace std;
long long a,b,ans,c1,c2,c3,cnt,to;
struct stu{
	long long a1,a2,a3;
}s1[100001];
struct st{
	long long a1,a2,a3;
}s2[100001];
struct stk{
	long long a1,a2,a3;
}s3[100001];
long long find1(){
	long long mni=1e7;
	for(int i=1;i<=c1;i++){
		if(mni>min((s1[i].a1-s1[i].a2),(s1[i].a1-s1[i].a3))){
			mni=min((s1[i].a1-s1[i].a2),(s1[i].a1-s1[i].a3));
			cnt=i;
			if((s1[i].a1-s1[i].a2)>(s1[i].a1-s1[i].a3)){
				to=3;
			}else{
				to=2;
			}
		}
	}
	return mni;
}
//----------------------------
long long find2(){
	
	long long mni=1e7;
	for(int i=1;i<=c2;i++){
		if(mni>min((s2[i].a2-s2[i].a1),(s2[i].a2-s2[i].a3))){
			mni=min((s2[i].a2-s2[i].a1),(s2[i].a2-s2[i].a3));
			//cout<<(s2[i].a2-s2[i].a1)<<(s2[i].a2-s2[i].a3)<<i<<endl;
			//cout<<s2[i].a1<<s2[i].a2<<s2[i].a3<<endl; 
			cnt=i;
			if((s2[i].a2-s2[i].a3)>(s2[i].a2-s2[i].a1)){
				to=1;
			}else{
				to=3;
			}
		}
	}
	
	return mni;
}
//----------------------------
long long find3(){
	long long mni=1e7;
	for(int i=1;i<=c3;i++){
		if(mni>min((s3[i].a3-s3[i].a1),(s3[i].a3-s3[i].a2))){
			mni=min((s3[i].a3-s3[i].a1),(s3[i].a3-s3[i].a2));
			cnt=i;
			if((s3[i].a3-s3[i].a2)>=(s3[i].a3-s3[i].a1)){
				to=1;
			}else{
				to=2;
			}
		}
	}
	return mni;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>a;
	for(int j=1;j<=a;j++){
		ans=0;c1=0;c2=0;c3=0;to=0;cnt=0;
		cin>>b;
		for(int i=1;i<=b;i++){
			long long w,ww,www;
			cin>>w>>ww>>www;
			if(w>=ww&&w>=www){
				s1[++c1].a1=w;
				s1[c1].a2=ww;
				s1[c1].a3=www;
				ans+=w;
			}else if(ww>=w&&ww>=www){
				s2[++c2].a1=w;
				s2[c2].a2=ww;
				s2[c2].a3=www;
				ans+=ww;
			}else if(www>=ww&&www>=w){
				s3[++c3].a1=w;
				s3[c3].a2=ww;
				s3[c3].a3=www;
				ans+=www;
			}}
			//cout<<ans<<endl; 
		for(;;){
			if(c1<=b/2&&c2<=b/2&&c3<=b/2)break;
		if(c1>(b/2)){
			find1(); 
		if(to=2){
			s2[++c2].a1=s1[cnt].a1; 
			s2[c2].a2=s1[cnt].a2;
			s2[c2].a3=s1[cnt].a3;
			s1[cnt].a1=s1[c1].a1;
			s1[cnt].a2=s1[c1].a2;
			s1[cnt].a3=s1[c1].a3;
		}else{
			s3[++c3].a1=s1[cnt].a1; 
			s3[c3].a2=s1[cnt].a2;
			s3[c3].a3=s1[cnt].a3;
			s1[cnt].a1=s1[c1].a1;
			s1[cnt].a2=s1[c1].a2;
			s1[cnt].a3=s1[c1].a3;
		}
		c1--;
		} 
		if(c2>(b/2)){
		find2();
		if(to=1){
			s1[++c1].a1=s2[cnt].a1; 
			s1[c1].a2=s2[cnt].a2;
			s1[c1].a3=s2[cnt].a3;
			s2[cnt].a1=s2[c2].a1;
			s2[cnt].a2=s2[c2].a2;
			s2[cnt].a3=s2[c2].a3;
		}else{
			s3[++c3].a1=s2[cnt].a1; 
			s3[c3].a2=s2[cnt].a2;
			s3[c3].a3=s2[cnt].a3;
			s2[cnt].a1=s2[c2].a1;
			s2[cnt].a2=s2[c2].a2;
			s2[cnt].a3=s2[c2].a3;
		}
		c2--;
		}
		if(c3>(b/2)){
		find3();;
		if(to=1){
			s1[++c1].a1=s3[cnt].a1; 
			s1[c1].a2=s3[cnt].a2;
			s1[c1].a3=s3[cnt].a3;
			s3[cnt].a1=s3[c3].a1;
			s3[cnt].a2=s3[c3].a2;
			s3[cnt].a3=s3[c3].a3;
		}else{
			s2[++c2].a1=s3[cnt].a1; 
			s2[c2].a2=s3[cnt].a2;
			s2[c2].a3=s3[cnt].a3;
			s3[cnt].a1=s3[c3].a1;
			s3[cnt].a2=s3[c3].a2;
			s3[cnt].a3=s3[c3].a3;
		}
		c3--;	
		}
		}
		ans=0;
		for(int i=1;i<=c1;i++){
			ans+=s1[i].a1 ;
		}
		for(int i=1;i<=c2;i++){
			ans+=s2[i].a2 ;
		}
		for(int i=1;i<=c3;i++){
			ans+=s3[i].a3 ;
		}
		cout<<ans<<endl;
		}
	return 0; 
}
