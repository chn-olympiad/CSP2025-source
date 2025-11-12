#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T, n, ja[100005], jb[100005], jc[100005], ans = 0;
int ia[100005], ib[100005], ic[100005];
int iav[100005], ibv[100005], icv[100005];
int iaa, iab, iac;
int key, mans = 0;
bool A = true, B = true;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin >> T;
	while(T--){
		mans = 0;
		cin >> n;
		iaa = iab = iac = n;
		for(int i = 1;i <= n;i++){
			cin >> ja[i] >> jb[i] >> jc[i];
			ia[i] = ja[i];
			ib[i] = jb[i];
			ic[i] = jc[i];
			iav[i] = ja[i];
			ibv[i] = jb[i];
			icv[i] = jc[i];
			if(jb[i] != 0 || jc[i] != 0){
				A = false;
			}if(jc[i] != 0){
				B = false;
			}	
		}
		sort(ja+1, ja+n+1);
		sort(jb+1, jb+1+n);
		sort(jc+1, jc+n+1);
		ans = 0;
		ans += ja[n];
		for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0; ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}
		iaa--;
		sort(ja+1, ja+n+1);
		sort(jb+1, jb+1+n);
		sort(jc+1, jc+n+1);
		for(int i = n;i > 0;i--){
			if(ja[n] >= jb[n] && ja[n] >= jc[n] && iaa > n/2){
				ans += ja[n];
				for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0; ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}
				sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iaa--;
			}else if(jb[n] >= ja[n] && jb[n] >= jc[n] && iab > n/2){
				ans += jb[n];
				for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						jb[n] = 0;ib[l] = 0;
						key = l;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iab--;
			}else if(jc[n] >= jb[n] && jc[n] >= ja[n] && iac > n/2){
				ans += jc[n];
				for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iac--;
			}else if(iaa > n/2 && iab > n/2){
				if(ja[n] >= jb[n]){
					ans += ja[n];
					for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iaa--;
				}else{
					ans += jb[n];
					for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0; 	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iab--;
				}
			}else if(iac > n/2 && iab > n/2){
				if(jc[n] >= jb[n]){
					ans += jc[n];
					for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
						ja[l] = 0;ia[key] = 0;
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iac--;
				}else{
					ans += jb[n];
					for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iab--;
				}
			}else if(iaa > n/2 && iac > n/2){
				if(ja[n] >= jc[n]){
					ans += ja[n];
					for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iaa--;
				}else{
					ans += jc[n];
					for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
						ja[l] = 0;ia[key] = 0;
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iac--;
				}
			}else if(iaa > n/2){
				ans += ja[n];
				for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iaa--;
			}else if(iab > n/2){
				ans += jb[n];
				for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					} 
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ib[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iab--;
			}else if(iac > n/2){
				ans += jc[n];
				for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iac--;
			}
		}mans = max(mans, ans);
		
		
		
		iaa = iab = iac = n;
		ans = 0;
		for(int i = 1;i <= n;i++){
			ia[i] = iav[i];
			ib[i] = ibv[i];
			ic[i] = icv[i];
			ja[i] = iav[i];
			jb[i] = ibv[i];
			jc[i] = icv[i];
			if(jb[i] != 0 || jc[i] != 0){
				A = false;
			}if(jc[i] != 0){
				B = false;
			}	
		}
		sort(ja+1, ja+n+1);
		sort(jb+1, jb+1+n);
		sort(jc+1, jc+n+1);
		ans += jb[n];
		for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						jb[n] = 0;ib[l] = 0;
						key = l;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}
		iab--;
		sort(ja+1, ja+n+1);
		sort(jb+1, jb+1+n);
		sort(jc+1, jc+n+1);
		for(int i = n;i > 0;i--){
			if(jb[n] >= ja[n] && jb[n] >= jc[n] && iab > n/2){
				ans += jb[n];
				for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						jb[n] = 0;ib[l] = 0;
						key = l;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iab--;
			}
			else if(ja[n] >= jb[n] && ja[n] >= jc[n] && iaa > n/2){
				ans += ja[n];
				for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0; ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}
				sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iaa--;
			}else if(jc[n] >= jb[n] && jc[n] >= ja[n] && iac > n/2){
				ans += jc[n];
				for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iac--;
			}else if(iaa > n/2 && iab > n/2){
				if(ja[n] >= jb[n]){
					ans += ja[n];
					for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iaa--;
				}else{
					ans += jb[n];
					for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0; 	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iab--;
				}
			}else if(iac > n/2 && iab > n/2){
				if(jc[n] >= jb[n]){
					ans += jc[n];
					for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
						ja[l] = 0;ia[key] = 0;
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iac--;
				}else{
					ans += jb[n];
					for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iab--;
				}
			}else if(iaa > n/2 && iac > n/2){
				if(ja[n] >= jc[n]){
					ans += ja[n];
					for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iaa--;
				}else{
					ans += jc[n];
					for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
						ja[l] = 0;ia[key] = 0;
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iac--;
				}
			}else if(iaa > n/2){
				ans += ja[n];
				for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iaa--;
			}else if(iab > n/2){
				ans += jb[n];
				for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					} 
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ib[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iab--;
			}else if(iac > n/2){
				ans += jc[n];
				for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iac--;
			}
		}mans = max(ans, mans);
		




		iaa = iab = iac = n;
		ans = 0;
		for(int i = 1;i <= n;i++){
			ia[i] = iav[i];
			ib[i] = ibv[i];
			ic[i] = icv[i];
			ja[i] = iav[i];
			jb[i] = ibv[i];
			jc[i] = icv[i];
			if(jb[i] != 0 || jc[i] != 0){
				A = false;
			}if(jc[i] != 0){
				B = false;
			}	
		}
		sort(ja+1, ja+n+1);
		sort(jb+1, jb+1+n);
		sort(jc+1, jc+n+1);
		ans += jc[n];
		for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}
		iac--;
		sort(ja+1, ja+n+1);
		sort(jb+1, jb+1+n);
		sort(jc+1, jc+n+1);
		for(int i = n;i > 0;i--){
			if(jc[n] >= jb[n] && jc[n] >= ja[n] && iac > n/2){
				ans += jc[n];
				for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iac--;
			}
			else if(jb[n] >= ja[n] && jb[n] >= jc[n] && iab > n/2){
				ans += jb[n];
				for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						jb[n] = 0;ib[l] = 0;
						key = l;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iab--;
			}
			else if(ja[n] >= jb[n] && ja[n] >= jc[n] && iaa > n/2){
				ans += ja[n];
				for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0; ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}
				sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iaa--;
			}else if(iaa > n/2 && iab > n/2){
				if(ja[n] >= jb[n]){
					ans += ja[n];
					for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iaa--;
				}else{
					ans += jb[n];
					for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0; 	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iab--;
				}
			}else if(iac > n/2 && iab > n/2){
				if(jc[n] >= jb[n]){
					ans += jc[n];
					for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
						ja[l] = 0;ia[key] = 0;
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iac--;
				}else{
					ans += jb[n];
					for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iab--;
				}
			}else if(iaa > n/2 && iac > n/2){
				if(ja[n] >= jc[n]){
					ans += ja[n];
					for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iaa--;
				}else{
					ans += jc[n];
					for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
						jb[l] = 0;ib[key] = 0; 
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
						ja[l] = 0;ia[key] = 0;
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
					iac--;
				}
			}else if(iaa > n/2){
				ans += ja[n];
				for(int l = 1;l <= n;l++){
					if(ia[l] == ja[n]){
						key = l;
						ja[n] = 0;
						ia[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0; 	
					}
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ic[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iaa--;
			}else if(iab > n/2){
				ans += jb[n];
				for(int l = 1;l <= n;l++){
					if(ib[l] == jb[n]){
						key = l;
						jb[n] = 0;
						ib[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					} 
				}for(int l = 1;l <= n;l++){
					if(jc[l] == ic[key]){
					jc[l] = 0;ib[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iab--;
			}else if(iac > n/2){
				ans += jc[n];
				for(int l = 1;l <= n;l++){
					if(ic[l] == jc[n]){
						key = l;
						jc[n] = 0;
						ic[l] = 0;
						break;
					}
				}for(int l = 1;l <= n;l++){
					if(jb[l] == ib[key]){
					jb[l] = 0;ib[key] = 0;	
					}
				}for(int l = 1;l <= n;l++){
					if(ja[l] == ia[key]){
					ja[l] = 0;ia[key] = 0;	
					}
				}sort(ja+1, ja+n+1);
				sort(jb+1, jb+1+n);
				sort(jc+1, jc+n+1);
				iac--;
			}
		}mans = max(mans, ans);
		
		
		
		cout << mans << endl ;
	}
		
	return 0;
} 