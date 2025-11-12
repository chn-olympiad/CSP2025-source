#include<bits/stdc++.h>
using namespace std;
int n,k,maxx,ka,a[500005],l1,l2,r1,r2;
vector<int> bits1,bits2,answer;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	r2=n;
	l1=1;
	for(int i=1;i<=n;i++){
		ka=i;
		r1=ka;
		l2=ka+1;
		int sum1=0,sum2=0;
		if(r1-l1==0 && r2-l2==0){
			sum1=a[l1];
			sum2=a[l2];
		}else if(r2-l2==0){
			sum2=a[l2];
		}else if(r1-l1==0){
			sum1=a[l1];
		}else{
			bool cmp=false;
			int shangci=0;
			for(int j=l1;j<=r1-1;j++){
				int qq=a[i];
				if(cmp==true){
					qq=shangci;
				}
				while(qq>0){
					bits1.push_back(qq%2);
					qq/=2;
				}
				qq=a[i+1];
				while(qq>0){
					bits2.push_back(qq%2);
					qq/=2;
				}
				if(bits1.size()>bits2.size()){
					for(int ii=0;ii<bits2.size();i++){
						if(bits1[i]==bits2[i]){
							answer.push_back(0);
						}else{
							answer.push_back(1);
						}
					}
				}
				if(bits1.size()<bits2.size()){
					for(int ii=0;ii<bits1.size();i++){
						if(bits1[i]==bits2[i]){
							answer.push_back(0);
						}else{
							answer.push_back(1);
						}
					}
				}
				if(bits1.size()==bits2.size()){
					for(int ii=0;ii<bits1.size();i++){
						if(bits1[i]==bits2[i]){
							answer.push_back(0);
						}else{
							answer.push_back(1);
						}
					}
				}
				cmp=true;
				for(int ii=answer.size()-1;ii>=0;ii--){
					int zhishu=answer.size()-ii-1;
					shangci+=answer[ii]*pow(2,zhishu);
				}
				while(!bits1.empty()){
					bits1.pop_back();
				}
				while(!bits2.empty()){
					bits1.pop_back();
				}
				while(!answer.empty()){
					bits1.pop_back();
				}
			}
			sum1=shangci;
			shangci=0;
			cmp=false;
			for(int j=l2;j<=r2-1;j++){
				int qq=a[i];
				if(cmp==true){
					qq=shangci;
				}
				while(qq>0){
					bits1.push_back(qq%2);
					qq/=2;
				}
				qq=a[i+1];
				while(qq>0){
					bits2.push_back(qq%2);
					qq/=2;
				}
				if(bits1.size()>bits2.size()){
					for(int ii=0;ii<bits2.size();i++){
						if(bits1[i]==bits2[i]){
							answer.push_back(0);
						}else{
							answer.push_back(1);
						}
					}
				}
				if(bits1.size()<bits2.size()){
					for(int ii=0;ii<bits1.size();i++){
						if(bits1[i]==bits2[i]){
							answer.push_back(0);
						}else{
							answer.push_back(1);
						}
					}
				}
				if(bits1.size()==bits2.size()){
					for(int ii=0;ii<bits1.size();i++){
						if(bits1[i]==bits2[i]){
							answer.push_back(0);
						}else{
							answer.push_back(1);
						}
					}
				}
				cmp=true;
				for(int ii=answer.size()-1;ii>=0;ii--){
					int zhishu=answer.size()-ii-1;
					shangci+=answer[ii]*pow(2,zhishu);
				}
				while(!bits1.empty()){
					bits1.pop_back();
				}
				while(!bits2.empty()){
					bits1.pop_back();
				}
				while(!answer.empty()){
					bits1.pop_back();
				}
			}
			sum2=shangci;
			cmp=false;
			shangci=0;
		}
		if(sum1==k && sum2==k){
			maxx++;
		}
	}
	cout<<maxx<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
/*
你知道吗？这道题目我写了2个多小时，发现题目理解错了，[哭笑]
我要上电视！ 
*/
