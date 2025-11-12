#include<bits/stdc++.h>
using namespace std;
int result[6];
int n;int a1 = 0,b1 = 0,c1 = 0;
vector<int>A1,B1,C1;
int A2[200] = {0};
int B2[200] = {0};
int C2[200] = {0};
vector<int> A,B,C;
int cha_ruB(int b);
int cha_ruC(int c);
int cha_ruA(int a){
	A.push_back(a);
	a1++;
	for(int i = 0;i<a1;i++){
  if(i+1==a1){
			break;
		}
		if(A[i+1]>A[i]){
			int k = A[i];
			A[i] = A[i+1];
			A[i+1] = k;
		}
	}
	if(a1>(n/2)){
		for(int i = 0;i<n;i++){
			if(A1[i] == A[a1-1]){
				A2[i] = 1;
				a1--;
				if(B1[i]>C1[i]&&B2[i]== 0){
					cha_ruB(B1[i]);
				}else if(C2[i] == 0){
					cha_ruC(C1[i]);
				}else{
					cha_ruB(B1[i]);
				}
				return a1;
			}
		}
	}
	return a1;
}
int cha_ruB(int b){
	B.push_back(b);
	b1++;
	for(int i = 0;i<b1-2;i++){
		if(B[i+1]>B[i]){
			int k = B[i];
			B[i] = B[i+1];
			B[i+1] = k;
		}

	}
	if(b1>(n/2)){
		for(int i = 0;i<n;i++){
			if(B1[i] == B[b1-1]){
				
				B2[i] = 1;
				b1--;
				if(C1[i]>=A1[i]&&C2[i]== 0){
					cha_ruC(C1[i]);
				}else if(A2[i] == 0){
					cha_ruA(A1[i]);
				}else{
					cha_ruC(C1[i]);
				}
				return b1;
			}
		}
	}
	return b1;
}
int cha_ruC(int c){
	C.push_back(c);
	c1++;
	for(int i = 0;i<c1;i++){
  if(i+1==c1){
			break;
		}
		if(C[i+1]>C[i]){
			int k = C[i];
			C[i] = C[i+1];
			C[i+1] = k;
		}
	}
	if(c1>(n/2)){
		for(int i = 0;i<n;i++){
			if(C1[i] == C[c1-1]){
				C2[i] = 1;
				c1--;
				if(A1[i]>B1[i]&&A2[i]== 0){
					cha_ruA(A1[i]);
				}else if(B[2] == 0){
					cha_ruB(B1[i]);
				}else{
					cha_ruA(A1[i]);
				}
				return c1;
			}
		}
	}
	return c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i = 0;i<T;i++){
		cin>>n;
		int a,c,b;
		a1 = 0,b1 = 0,c1 = 0;
		for(int j = 0;j<n;j++){
			cin>>a>>b>>c;
			A1.push_back(a);B1.push_back(b);C1.push_back(c);
			if(a == max(max(a,b),c)){
				cha_ruA(a);
			}else if(b == max(max(a,b),c)){
				cha_ruB(b);
			}else{
				cha_ruC(c);
			}
		}
		result[i] = 0;
		for(int j = 0;j<a1;j++){
			result[i]+=A[j];
		}
		for(int j = 0;j<b1;j++){
			result[i] +=B[j];
		}
		for(int j = 0;j<c1;j++){
			result[i] +=C[j];
		}
		A.clear();B.clear();C.clear();
		A1.clear();B1.clear();C1.clear();
	}
	for(int i = 0;i<T;i++) cout<<result[i]<<endl;
	return 0;
	}

