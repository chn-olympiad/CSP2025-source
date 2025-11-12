#include <bits/stdc++.h>
using namespace std;
int p[10000];
int p1=0;
int p2=0;
int p3=0;
int res[10000];
int pointer=0;
struct part{
	int id;
	int member;
};
string equal(int one,int two,int thr){
	if (one==two){
		return "12";
	}
	else if (two==thr){
		return "23";
	}
	else if (one==thr){
		return "13";
	}
}
int compare(int one,int two,int thr){
	int maxn;
	string eq=equal(one,two,thr);
	if (eq=="12"){
		return max(one,thr);
	}
	else if (eq=="23"){
		return max(one,two);
	}
	else if (eq=="13"){
		return max(one,two);
	}
	if (one>two && one>thr){
		maxn=one;
	}
	else if (two>one && two>thr){
		maxn=two;
	}
	else{
		maxn=thr;
	}
	return maxn;
}
int compare2(int one,int two,int thr){
	int med,maxn;
	string eq=equal(one,two,thr);
	if (eq=="12"){
		return max(one,thr);
	}
	else if (eq=="23"){
		return max(one,two);
	}
	else if (eq=="13"){
		return max(one,two);
	}
	maxn=compare(one,two,thr);
	if (maxn==one){
		if (two>thr){
			med=two;
		}
		else{
			med=thr;
		}
	}
	else if (maxn==two){
		if (one>thr){
			med=one;
		}
		else{
			med=thr;
		}
	}
	else{
		if (one>two){
			med=one;
		}
		else{
			med=two;
		}
	}
	return med;
}
int comparen(int one,int two){
	if (one>two){
		return one;
	}
	else{
		return two;
	}
}
int compare3(int one,int two,int thr){
	int min,med,max;
	max=compare(one,two,thr);
	med=compare2(one,two,thr);
	min=(one+two+thr)-max-med;
	return min;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int extra=0;
	int c=1;
	int b1c=0;
	int b2c=0;
	int b3c=0;
	int num=1;
	int ans=0;
	part b1;
	part b2;
	part b3;
	b1.id=1;
	b2.id=2;
	b3.id=3;
	int a1,a2,a3;
	int limit;
	cin>>t;
	for (int i=0;i<t;i++){
		c=1;
		num=1;
		b1c=0;
		b2c=0;
		b3c=0;
		b1.member=0;
		b2.member=0;
		b3.member=0;
		cin>>n;
		limit=n/2;
		for (int j=0;j<n;j++){
			cin>>p[c]>>p[c+1]>>p[c+2];
			c+=3;
		}
		ans=c/3;
		for (int j=0;j<ans;j++){
			a1=p[num];
			a2=p[num+1];
			a3=p[num+2];
			if (compare(a1,a2,a3)==a1){
				if (b1c<limit){
					b1.member+=a1;
					b1c++;
				}
				else{
					if (compare2(a1,a2,a3)==a2){
						if (b2c<limit){
							b2.member+=a2;
							b2c++;
						}
						else{
							b3.member+=a3;
							b3c++;
						}
					}
					else if (compare2(a1,a2,a3)==a3){
						if (b3c<limit){
							b3.member+=a3;
							b3c++;
						}
						else{
							b2.member+=a2;
							b2c++;
						}
					}
				}
			}
			if (compare(a1,a2,a3)==a2){
				if (b2c<limit){
					b2.member+=a2;
					b2c++;
				}
				else{
					if (compare2(a1,a2,a3)==a1){
						if (b1c<limit){
							b1.member+=a1;
							b1c++;
						}
						else{
							b3.member+=a3;
							b3c++;
						}
					}
					else if (compare2(a1,a2,a3)==a3){
						if (b3c<limit){
							b3.member+=a3;
							b3c++;
						}
						else{
							b2.member+=a1;
							b2c++;
						}
					}
				}
			}
			if (compare(a1,a2,a3)==a3){
				if (b3c<limit){
					b3.member+=a3;
					b3c++;
				}
				else{
					if (compare2(a1,a2,a3)==a1){
						if (b1c<limit){
							b1.member+=a1;
							b1c++;
						}
						else{
							b2.member+=a2;
							b2c++;
						}
					}
					else if (compare2(a1,a2,a3)==a2){
						if (b2c<limit){
							b2.member+=a2;
							b2c++;
						}
						else{
							b1.member+=a1;
							b1c++;
						}
					}
				}
			}
			num+=3;
		}
		//cout<<b1.member+b2.member+b3.member<<endl;
		res[pointer]=b1.member+b2.member+b3.member;
		pointer++;
	}
	for (int i=0;i<t;i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
