#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct way{
	ll rate;
	ll A;
	ll B;
	ll C;
};

struct signi{
	ll toA;
	ll toB;
	ll toC;
};

bool abc(signi a, signi b){
	ll as=max(a.toA,max(a.toB,a.toC));
	ll bs=max(b.toA,max(b.toB,b.toC));
	return as<bs;
}

//bool greater(way a, way b, ll n, )
//{
//	ll lim = n / 2;
//	if(a.A > lim || a.B > lim || a.C > lim){
//		return false;
//	}
//	if(a.rate > b.rate){
//		return true;
//	}
//	return false;
//}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;cin>>T;
	for(int i = 0; i < T;++i){
		ll n; cin>>n;
		vector<signi> sig(n);
		
		bool spA=1, spB=1;
		
		for(int j = 0;j<n;++j){
			cin>>sig[j].toA>>sig[j].toB>>sig[j].toC;
		}
		for(auto s: sig){
			if(s.toC!=0){
				spA=0;spB=0;
				break;
			}
			if(s.toB!=0){
				spA=0;
			}
		}
		if(spA){//low to high
			way res={0,0,0,0};
			sort(sig.begin(), sig.end(),[=](signi a, signi b)
			{
				if(a.toA > b.toA){
					return 0;
				}
				return 1;
			});
			for(int qq=0; qq<n/2;++qq){
				res.rate += sig.back().toA;
				res.A++;
				sig.pop_back();
			}
			cout << res.rate ;
		}
		else if(spB && !spA){
			way res = {0,0,0,0};
			sort(sig.begin(), sig.end(), [=](signi a, signi b)
			{
				ll as=max(a.toA,a.toB);
				ll bs=max(b.toA,b.toB);
				if(as < bs)return 1;
				return 0;
			});
	
			while(!sig.empty()){
			
				auto s = sig.back();
				if(s.toA > s.toB){
					if(res.A < n/2){
						res.rate+=s.toA;
						++res.A;
					}
					else {
					res.rate+=s.toB; 
					res.B++;}
				}else{
					if(res.B < n/2){
						res.rate+=s.toB;
						++res.B;
					}
					else {
					res.rate+=s.toA; 
					++res.A;}
				}
				sig.pop_back();
			}
			cout << res.rate << '\n';
		}
		else{
			way w = {0,0,0,0};
			sort(sig.begin(), sig.end(), abc);
			while(!sig.empty()){
				
				auto a = sig.back();
				ll as=max(max(a.toA,a.toB),a.toC);
				if(a.toA == as) {
					if(w.A < n/2){
						w.rate+=as;
						w.A++;
					}
					else if(a.toB > a.toC){
						w.rate+=a.toB;
						w.B++;
					}
					else{
						w.rate+=a.toC;
						w.C++;
					}
				}
				else if(a.toB == as) {
					if(w.B < n/2){
						w.rate+=as;
						w.B++;
					}
					else if(a.toA > a.toC){
						w.rate+=a.toA;
						w.A++;
					}
					else{
						w.rate+=a.toC;
						w.C++;
					}
				}
				else if(a.toC == as) {
					if(w.C < n/2){
						w.rate+=as;
						w.C++;
					}
					else if(a.toA > a.toB){
						w.rate+=a.toA;
						w.A++;
					}
					else{
						w.rate+=a.toB;
						w.B++;
					}
				}
				sig.pop_back();
			}
			cout << w.rate << '\n';
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
