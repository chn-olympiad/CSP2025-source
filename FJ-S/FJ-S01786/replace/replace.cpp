#include<iostream>
#include<cstring>
using namespace std;
string t1,t2,x,y,z,s1[200010],s2[200010],str;
bool cu[200010],ifu[200010] = {false},h[200010][5000010],change[200010] = {false},flag;
long long n,q,len[200010],i,k;
int main(){
	cin>>n>>q;
	for(long long c = 1;c <= n;c++){
		cin>>s1[c]>>s2[c];
		len[c] = s1[c].size();
	}
	while(q--){
		cin>>t1>>t2;
		k = 0;
		for(long long c = 1;c <= n;c++){
			for(long long c1 = 1;c1 <= t1.size();c1++){
				h[c][c1] = false;
			}
		}
		if(t1.size() != t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(long long c = 1;c <= n;c++){
			flag = false;
			cu[c] = false;
			for(long long p = 0;p + len(c) <= t1.size()-1;p++){
				str = "";
				for(long long c1 = p;c1 <= p+len[c];c1++){
					str += t1[c1];
				}
				if(str != s1[c]){
					continue;
				}
				str = "";
				for(long long c1 = p;c1 <= p+len[c];c1++){
					str += t2[c1];
				}
				if(str == s2[c]){
					flag = true;
					h[c][p] = true;
				}
			}
			if(flag){
				cu[c] = true;
			}
		}
		while(!ifu[n+1]){
			if(cu[1]){
				i = 1;
				for(long long c = 1;ifu[c]||(!cu[c]);c++){
					ifu[c] = false;
					i = c;
				}
				ifu[i+1] = true;
			}
			else{
				ifu[1] = true;
			}
			if(ifu[n+1]){
				break;
			}
			for(long long c = 1;c <= t1.size();c++){
				change[c] = false;
			}
			for(long long c = 1;c <= n;c++){
				for(long long c1 = 0;c1 <= t1.size();c1++){
					if(h[c][c1]){
						for(long long c2 = c1;c2 <= c1+len[c];c2++){
							change[c2] = true;
						}
					}
				}
			}
			flag = true;
			for(long long c = 1;c <= t1.size();c++){
				if(change[c]){
					continue;
				}
				if(t1[c] != t2[c]){
					flag = false;
					break;
				}
			}
			if(flag){
				k++;
			}
		}
		cout<<k<<endl;
	}
return(0);
}

