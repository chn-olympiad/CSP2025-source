#include<bits/stdc++.h>
using namespace std;
long long T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int Tt=0;Tt<T;Tt++){
		long long a=0,d1,d2,d3,d4,d5,f=0,g=0,h=0,j=0,k=0,l=0,s1=0,s2=0,s3=0,ans=0;
		cin>>a;
		priority_queue<long long,vector<long long>,greater<long long> > q1;
		priority_queue<long long,vector<long long>,greater<long long> > q2;
		priority_queue<long long,vector<long long>,greater<long long> > q3;
		for(int i=1;i<=a;i++){
			cin>>d1>>d2>>d3;
			d4=max(d1,max(d2,d3));
			if(d4==d1){
				d5=max(d2,d3);
				if(s1<a/2){
					s1++;
					q1.push(d4-d5);
					ans+=d4;
				}
				else{
					if(q1.top()>d4-d5){
						ans+=d5;
					}
					else{
						ans-=q1.top();
						q1.pop();
						q1.push(d4-d5);
						ans+=d4;
					}
				}
			}
			else if(d4==d2){
				d5=max(d1,d3);
				if(s2<a/2){
					s2++;
					q2.push(d4-d5);
					ans+=d4;
				}
				else{
					if(q2.top()>d4-d5){
						ans+=d5;
					}
					else{
						ans-=q2.top();
						q2.pop();
						q2.push(d4-d5);
						ans+=d4;
					}
				}
			}
			else{
				d5=max(d1,d2);
				if(s3<a/2){
					s3++;
					q3.push(d4-d5);
					ans+=d4;
				}
				else{
					if(q3.top()>d4-d5){
						ans+=d5;
					}
					else{
						ans-=q3.top();
						q3.pop();
						q3.push(d4-d5);
						ans+=d4;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
