#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}










int ans(){
	int sum = 0;
	int suma1 = 0;
	int suma2 = 0;
	int suma3 = 0;
	
	int j3 = 0;
		for(int j = n;j>0;j--){
			cout<<a1[j3]<<" "<<a2[j3]<<" "<<a3[j3]<<endl;
			j3++;
		}
		
	int j2 = 0;
	for(int j = n;j>0;j--){
		if(suma1<n/2 && suma2<n/2 && suma3<n/2){
			sum += max(max(a1[j2],a2[j2]),a3[j2]);	
		}
		else if(suma1>=n/2){
			sum += max(a2[j2],a3[j2]);
		}
		else if(suma2>=n/2){
			sum += max(a1[j2],a3[j2]);
		}
		else if(suma3>=n/2){
			sum += max(a1[j2],a2[j2]);
		}
		
		if(max(max(a1[j2],a2[j2]),a3[j2]) == a1[j2]){
			suma1++;
		}
		else if(max(max(a1[j2],a2[j2]),a3[j2]) == a2[j2]){
			suma2++;
		}
		else if(max(max(a1[j2],a2[j2]),a3[j2]) == a3[j2]){
			suma3++;
		}
		j2++;	
	}
	return sum;
}
