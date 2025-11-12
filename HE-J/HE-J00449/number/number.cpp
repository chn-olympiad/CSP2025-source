#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string input;
	cin >> input;
	int input_numbers_counter = 0;
	for(int i = 0;i <= input.length();i++){
		if(input[i] == '1'){
			input_numbers_counter++;
		}else if(input[i] == '2'){
			input_numbers_counter++;
		}else if(input[i] == '3'){
			input_numbers_counter++;
		}else if(input[i] == '4'){
			input_numbers_counter++;
		}else if(input[i] == '5'){
			input_numbers_counter++;
		}else if(input[i] == '6'){
			input_numbers_counter++;
		}else if(input[i] == '7'){
			input_numbers_counter++;
		}else if(input[i] == '8'){
			input_numbers_counter++;
		}else if(input[i] == '9'){
			input_numbers_counter++;
		}else if(input[i] == '0'){
			input_numbers_counter++;
		}else{
			continue;
		}
		//cout << in << endl;
	}
	int input_numbers[input_numbers_counter];
	for(int i = 0; i <= input_numbers_counter;i++){
		int in = -114514;
		if(input[i] == '1'){
			in = 1;
		}else if(input[i] == '2'){
			in = 2;
		}else if(input[i] == '3'){
			in = 3;
		}else if(input[i] == '4'){
			in = 4;
		}else if(input[i] == '5'){
			in = 5;
		}else if(input[i] == '6'){
			in = 6;
		}else if(input[i] == '7'){
			in = 7;
		}else if(input[i] == '8'){
			in = 8;
		}else if(input[i] == '9'){
			in = 9;
		}else if(input[i] == '0'){
			in = 0;
		}else{
			continue;
		}
		input_numbers[i] = in;
	}
	int last_number=0,max_number=0;
	int sort_numbers[input_numbers_counter];
	#ifdef DEBUG
	cout << "[DEBUG][3] ";
	#endif // DEBUG
	for(int i = 0; i <= input_numbers_counter;i++){
		sort_numbers[i] = input_numbers[i];
		#ifdef DEBUG
        cout << sort_numbers[i];
		#endif // DEBUG
	}
	#ifdef DEBUG
	cout << endl;s
	#endif // DEBUG

	for (int j = 0;j < input_numbers_counter;j++){
		for (int i = 0;i < input_numbers_counter;i++){
			#ifdef DEBUG
			cout << "[DEBUG][1]" << "i:"  << i << " " << sort_numbers[i] << " " << sort_numbers[i+1] << endl;
			#endif
			if((i+1 <= input_numbers_counter) && (sort_numbers[i+1] > sort_numbers[i])){
				int temp_a = sort_numbers[i+1],temp_c = sort_numbers[i];
				sort_numbers[i+1] = temp_c;
				sort_numbers[i] = temp_a;
				#ifdef DEBUG
				cout << "[DEBUG][2]" << sort_numbers[i] << " " << sort_numbers[i+1] << endl;
				#endif
			}
		}
	}





	for (int sss = 0;sss < input_numbers_counter;sss++){
		cout << sort_numbers[sss];
	}
	return 0;
}
