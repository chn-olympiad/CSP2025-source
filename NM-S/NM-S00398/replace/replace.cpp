#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
const ll M=2e3+10;
ll n,q,f_be=-1,f_en=-1,cnt=0;
ll chsize[N],q1size=0,q2size=0,p,fff=0;
char ch1[N][M],ch2[N][M];
char q1[M],q2[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		p=0;
		cin>>ch1[i]>>ch2[i];
		while(ch1[i][p]){
			chsize[i]++;p++;
		}p=0;
	}
	while(q--){
	ll cnt=0;
	q1size=0,q2size=0;
	p=0;
	f_be=-1,f_en=-1;
	cin>>q1>>q2;
	while(q1[p]){
		q1size++;p++;
	}p=0;
	while(q2[p]){
		q2size++;p++;
	}
	//cout<<chsize[1]<<" "<<q1size<<" "<<q2size<<endl;
	for(int i=0;i<q1size;i++){
		if(q1[i]!=q2[i]&&f_be==-1) f_be=i;
		if(q1[i]!=q2[i]&&i==q1size-1&&f_en==-1) f_en=i;
		else if(q1[i]==q2[i]&&q1[i-1]!=q2[i-1]) f_en=i-1;
	}
	//cout<<"f_be/f_en"<<f_be<<" "<<f_en<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=q1size-chsize[i];j++){
			ll tt=j;
			for(int k=0;k<chsize[i];k++){
				//cout<<q1[j]<<" "<<ch1[i][k]<<" "<<q2[j]<<" "<<ch2[i][k]<<endl;
				if(q1[tt]!=ch1[i][k] || q2[tt]!=ch2[i][k]){
					//cout<<q1[j]<<" "<<ch1[i][k]<<" "<<q2[j]<<" "<<ch2[i][k]<<endl;
					fff=1;break;
				}else tt++;
			}
			if(fff==1){
				fff=0;
				continue;
			}
			else{
				if(j<=f_be&&(j+chsize[i])>f_en){
					//cout<<"i "<<i <<" j "<<j<<endl;
	    			//cout<<"chsize "<<chsize[i]<<endl;
					//cout<<"f_be "<<f_be<<" f_en "<<f_en<<endl;
					cnt++;
				}
				else continue;
			}
		}
	}
	cout<<cnt<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
