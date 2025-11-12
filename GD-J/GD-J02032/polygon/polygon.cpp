#include <bits/stdc++.h>
using namespace std;

string AddBinary(string a){
	auto IT = find(a.begin(),a.end(),'0');
	int StringLen = a.size();
	string copy_a = "";
	string copy_copy_a = "";
	if(IT == a.end()){
		return "null";
	}
	for(int i = a.size() - 1;i >= 0;i--){
		copy_a += a[i];
	}
	bool b = false;
	int Pla = 0;
	
	if(copy_a[0] == '0'){
		copy_a[0] = '1';
	}else{
		copy_a[0] = '0';
		b = true;
	}
	Pla = 1;
	while(b && Pla <= a.size() - 1){
		if(copy_a[Pla] == '0'){
			copy_a[Pla] = '1';
			b = false;
		}else{
			copy_a[Pla] = '0';
			b = true;
		}
		Pla++;
	}
	if(b){
		copy_a += '1'; 
	}
	
	for(int i = copy_a.size() - 1;i >= 0;i--){
		copy_copy_a += copy_a[i];
	}
	
	return copy_copy_a;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	vector<int> SticK;
	long long NuM = 0;
	cin >> NuM;
	long long PosB_Sit = 0;
	string IFcul = "";
	for(int i = 0;i < NuM;i++){
		IFcul += '0';
	}
	
	for(int i = 0;i < NuM;i++){
		int StiLeN = 0;
		cin >> StiLeN;
		SticK.push_back(StiLeN); 
	}
	sort(SticK.begin(),SticK.end(),greater<int>());
	
	IFcul = AddBinary(IFcul);
	while(IFcul != "null"){ 
		vector<int> a;
		for(int i = 0;i < IFcul.size();i++){
			if (IFcul[i] != '0'){
				a.push_back(SticK[i]);
			}
		} 
		if(a.size() < 3){
			IFcul = AddBinary(IFcul);
			continue;
		}
		long long max = a[0];
		long long sum = 0;
		for(int i = 0;i < a.size();i++){
			sum += a[i];
		}
		if(sum > 2*max){
			PosB_Sit++;
		}
		IFcul = AddBinary(IFcul);
	}
	cout << PosB_Sit % 998244353;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
